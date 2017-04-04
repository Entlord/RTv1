#include <rt.h>
#define SKYBOX_R	0
#define SKYBOX_G	99
#define SKYBOX_B	99

const t_dict_obj dict[] =
{
	{SPHERE, get_intersect_sphere},
    { 0x0, NULL }
};

void	render_pixel(t_map *map, t_img *image, int x, int y)
{
	t_color		sky;
	t_object	*obj;
	t_object	*nearest;
	float		intersect_tmp;
	float		intersect_min;
	int			i;

	nearest = NULL;
	sky = get_color(SKYBOX_R, SKYBOX_G, SKYBOX_B);
	t_vector	cam_vector;

	cam_vector = get_camera_vector(map->cam, x, y);
	(void)sky;
	(void)image;

	intersect_min = -1;
	obj = map->object;
	while(obj)
	{
		i = 0;
		while (dict[i].type != 0 && dict[i].type != obj->type)
			i++;

		if (dict[i].type != 0)
		{

			intersect_tmp = dict[i].f(map->cam->position, cam_vector, obj->object);
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

	if (nearest == NULL)
		// draw_pixel(x, y, &sky);
		cpy_pixel(&sky, &image->pixel[x][y]);
	else
	{
		t_ball *n;
		n = nearest->object;
		// draw_pixel(x, y, &n->color);
		cpy_pixel(&n->color, &image->pixel[x][y]);
	}

	// intersect = get_intersect_sphere(map->cam->position, cam_vector, (t_ball*)(map->object->next->object));
	// // printf("%f\n", intersect);

	// cpy_pixel(&sky, &(image->pixel[x][y]));
	// if (intersect == -1)
	// 	draw_pixel(x, y, &sky);
	// else
	// 	draw_pixel(x, y, &sphere.color);
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
