#include "libft.h"
#include "main.h"

int		main()
{
	init_window(200, 200);

	for (int x = 0; x < 200; x++) for (int y = 0; y < 200; y++)
		draw_pixel(x, y, 255, 255, 0);

	copy_image_to_window();
	SDL_Delay(500);

	clear_image();
	SDL_Delay(500);

	free_resources();
	return (0);
}
