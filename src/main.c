#include "libft.h"
#include "main.h"

int		main(void)
{
	init_window(200, 200);
	clear_image();
	copy_image_to_window();
	SDL_Delay(500);
	clear_image();
	SDL_Delay(500);
	free_resources();
	return (0);
}
