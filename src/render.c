#include <rt.h>
#define SKYBOX_R	0
#define SKYBOX_G	99
#define SKYBOX_B	99

static const t_dict_obj dict[] =
{
	{SPHERE, get_intersect_sphere},
    { 0x0, NULL }
};

static t_ptr_intersect get_intersect_function(int type)
{
	int	i;

	i = 0;
	while (dict[i].type != 0x0 && dict[i].type != type)
		i++;
	if (dict[i].type == 0x0)
		return (NULL);
	else
		return (dict[i].f);
}

static t_object	*intersect_object(t_map *map, t_vector ray)
{
	t_object	*obj;
	t_object	*nearest;
	float		intersect_tmp;
	float		intersect_min;

	intersect_min = -1;
	obj = map->object;
	while (obj)
	{
		if (get_intersect_function(obj->type))
		{
			intersect_tmp = get_intersect_function(obj->type)(map->cam->position, ray, obj->object);
			if (intersect_tmp == -1)
				intersect_tmp = intersect_tmp;
			else if (intersect_min == -1 || intersect_tmp < intersect_min)
			{
				intersect_min = intersect_tmp;
				nearest = obj;
			}
		}
		obj = obj->next;
	}
	return (intersect_min != -1 ? nearest : NULL);
}

void	render_pixel(t_map *map, t_img *image, int x, int y)
{
	t_color		sky;
	t_object	*nearest;
	t_vector	cam_vector;

	sky = get_color(SKYBOX_R, SKYBOX_G, SKYBOX_B);
	cam_vector = get_camera_vector(map->cam, x, y);
	nearest = intersect_object(map, cam_vector);
	if (nearest == NULL)
		cpy_pixel(&sky, &image->pixel[x][y]);
	else
	{
		cpy_pixel(&((t_ball*)nearest->object)->color, &image->pixel[x][y]);
	}
}

void	render_map(t_map *map, t_img *image)
{
	int			x;
	int			y;

	fill_collision_box(map->object);
	y = 0;
	while (y < image->height)
	{
		x = 0;
		while (x < image->width)
		{
			render_pixel(map, image, x, y);
			assert(image->pixel[x][y].r ||image->pixel[x][y].g ||image->pixel[x][y].b);
			x++;
		}
		y++;
	}
}
