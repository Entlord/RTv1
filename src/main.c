#include <libft.h>
#include <rt.h>

int main(void)
{
	t_map	map;
	t_cam cam;
	t_img	img;

	cam.direction.x = 0;
	cam.direction.y = 1;
	cam.direction.z = 0;
	cam.position.x = 0;
	cam.position.y = 0;
	cam.position.z = 0;
	cam.height = 100;
	cam.width = 100;
	cam.fov = 60;

	img.height = 100;
	img.width = 100;
	img.pixel = malloc(sizeof(t_color*) * 100);

	int	x = 0;

	while (x < img.width)
	{
		img.pixel[x] = ft_memalloc(sizeof(t_color) * 100);
		x++;
	}

	map.cam = &cam;


	vector_normalize(&cam.direction);

	init_window(600, 400);
	while (1)
	{
		render_map(&map, &img);
		handle_events();
	}
	return (0);
}
