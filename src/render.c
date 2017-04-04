#include <rt.h>
#define SKYBOX_R	0
#define SKYBOX_G	99
#define SKYBOX_B	99

void	render_pixel(t_map *map, t_img *image, int x, int y)
{
	(void)map;
	t_color	sky;
	float	intersect;

	sky = get_color(SKYBOX_R, SKYBOX_G, SKYBOX_B);
	t_vector	cam_vector;
	t_ball	sphere;

	sphere.position.x = 0;
	sphere.position.y = 3;
	sphere.position.z = 0;
	sphere.radius = 1;
	sphere.color = get_color(255, 0, 0);

	cam_vector = get_camera_vector(map->cam, x, y);

	intersect = get_intersect_sphere(map->cam->position, cam_vector, sphere);
	// printf("%f\n", intersect);

	cpy_pixel(&sky, &(image->pixel[x][y]));
	if (intersect == -1)
		// draw_pixel(x, y, &sky);
		image->pixel[x][y] = sky;
	else
		// draw_pixel(x, y, &sphere.color);
		image->pixel[x][y] = sphere.color;
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
			x++;
		}
		y++;
	}
	draw_img(image);
	refresh_window();
}
