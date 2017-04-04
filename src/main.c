#include <libft.h>
#include <rt.h>

void	new_sphere(t_object *root, int id, t_coor pos, t_color color, int radius)
{
	t_object	*node;
	t_ball		*sphere;

	sphere = malloc(sizeof(t_ball));
	sphere->position = pos;
	sphere->color = color;
	sphere->radius = radius;

	node = malloc(sizeof(t_object));
	node->id = id;
	node->type = SPHERE;
	node->object = sphere;
	node->next = NULL;

	while (root->next != NULL)
		root = root->next;
	
	root->next = node;
}

t_coor new_pos(float x, float y, float z)
{
	t_coor	pos;

	pos.x = x;
	pos.y = y;
	pos.z = z;
	return (pos);
}

int main(void)
{
	t_map	map;
	t_cam cam;
	t_img	img;

	cam.direction.x = 0;
	cam.direction.y = 1;
	cam.direction.z = 0;
	cam.position.x = 0;
	cam.position.y = -3;
	cam.position.z = 0;
	cam.height = 400;
	cam.width = 400;
	cam.fov = 60;

	img.height = 400;
	img.width = 400;
	img.pixel = malloc(sizeof(t_color*) * 400);

	int	x = 0;

	while (x < img.width)
	{
		img.pixel[x] = ft_memalloc(sizeof(t_color) * 400);
		x++;
	}

	map.cam = &cam;
	map.object = malloc(sizeof(t_object));
	map.object->id = 0;
	map.object->type = CONE;
	map.object->object = malloc(sizeof(t_cone));
	map.object->next = NULL;
	new_sphere(map.object, 1, new_pos(0, 5, 0), get_color(255, 0, 0), 1);
	new_sphere(map.object, 2, new_pos(1, 5, 0), get_color(0, 255, 0), 1);
	// new_sphere(map.object, 3, new_pos(0, 5, 0), get_color(0 ,255, 0), 1);
	// new_sphere(map.object, 3, new_pos(0, 40, -5), get_color(255 ,255, 255), 2);

	vector_normalize(&cam.direction);

	init_window(800, 800);
	render_map(&map, &img);
	while (1)
		handle_events();
	return (0);
}