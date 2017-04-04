#include <rt.h>

int    				init_window(int width, int height)
{
	int				fail;

	fail = SDL_Init(SDL_INIT_VIDEO) || SDL_CreateWindowAndRenderer(
	width, height,
	SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE,
	&get_sdl_data()->window, &get_sdl_data()->renderer);
	get_sdl_data()->width = width;
	get_sdl_data()->height = height;
	return (fail != 0);
}

int    				free_resources(void)
{
	if (get_sdl_data()->window != NULL)
		SDL_DestroyWindow(get_sdl_data()->window);
	if (get_sdl_data()->renderer != NULL)
		SDL_DestroyRenderer(get_sdl_data()->renderer);
	SDL_Quit();
	return (1);
}

int    				clear_image(void)
{
	int				fail;

	if (get_sdl_data()->renderer == NULL || get_sdl_data()->renderer == NULL)
		return (0);
	fail = SDL_SetRenderDrawColor(get_sdl_data()->renderer, 0, 0, 0, 255)
	|| SDL_RenderClear(get_sdl_data()->renderer)
	|| refresh_window();
	return (fail != 0);
}


int    				refresh_window(void)
{
	if (get_sdl_data()->renderer != NULL)
		SDL_RenderPresent(get_sdl_data()->renderer);
	else
		return (0);
	return (1);
}
