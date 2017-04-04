#include <rt.h>

static t_sdl_data	g_sdl_data = {
	NULL,
	NULL,
	0,
	0
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
	g_sdl_data.width = width;
	g_sdl_data.height = height;
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

	if (g_sdl_data.renderer == NULL || g_sdl_data.renderer == NULL)
		return (0);
	fail = SDL_SetRenderDrawColor(g_sdl_data.renderer, 0, 0, 0, 255)
	|| SDL_RenderClear(g_sdl_data.renderer)
	|| refresh_window();
	return (fail != 0);
}

int					draw_pixel(int x, int y, t_color *color)
{
	int				fail;

	if (g_sdl_data.renderer == NULL)
		return (0);
	fail = SDL_SetRenderDrawColor(g_sdl_data.renderer,
	color->r, color->g, color->b, 255)
	|| SDL_RenderDrawPoint(g_sdl_data.renderer, x, y);
	return (fail != 0);
}

int    				refresh_window(void)
{
	if (g_sdl_data.renderer != NULL)
		SDL_RenderPresent(g_sdl_data.renderer);
	else
		return (0);
	return (1);
}

int					draw_img(t_img *img)
{
	int		x;
	int		y;
	int		scale_x;
	int		scale_y;

	scale_x = img->width / g_sdl_data.width;
	scale_y = img->height / g_sdl_data.height;
	y = 0;
	while (y < g_sdl_data.height)
	{
		x = 0;
		while (x < g_sdl_data.width)
		{
			if (!draw_pixel(x, y, &img->pixel[x*scale_x][y*scale_y]))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void				handle_events(void)
{
	SDL_Event	event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			exit(0);
		}
	}
}
