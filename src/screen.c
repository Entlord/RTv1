#include "screen.h"

static t_sdl_data	g_sdl_data = {
	NULL,
	NULL
};


int					set_color(int r, int g, int b)
{
	int				fail;

	if (g_sdl_data.renderer == NULL)
		return (0);
	fail = SDL_SetRenderDrawColor(g_sdl_data.renderer, r, g, b, 255);
	return (fail != 0);
}


int    				init_window(int width, int height)
{
	int				fail;

	fail = SDL_Init(SDL_INIT_VIDEO) || SDL_CreateWindowAndRenderer(
	width, height,
	SDL_WINDOW_SHOWN, &g_sdl_data.window, &g_sdl_data.renderer);
	return (fail != 0);
}

int    				free_resources(void)
{
	if (g_sdl_data.window != NULL)
		SDL_DestroyWindow(g_sdl_data.window);
	if (g_sdl_data.renderer != NULL)
		SDL_DestroyRenderer(g_sdl_data.renderer);
	SDL_Quit();
	return (1);
}

int    				clear_image(void)
{
	int				fail;

	fail = SDL_SetRenderDrawColor(g_sdl_data.renderer, 0, 0, 0, 255)
	|| SDL_RenderClear(g_sdl_data.renderer)
	|| copy_image_to_window();
	return (fail != 0);
}

int					draw_pixel(int x, int y, t_color *color)
{
	int				fail;

	fail = SDL_SetRenderDrawColor(g_sdl_data.renderer,
	color->r, color->g, color->b, 255)
	|| SDL_RenderDrawPoint(g_sdl_data.renderer, x, y);
	return (fail != 0);
}

int    				copy_image_to_window(void)
{
	int				fail;

	fail = g_sdl_data.renderer == NULL;
	if (!fail)
		SDL_RenderPresent(g_sdl_data.renderer);
	return (fail != 0);
}
