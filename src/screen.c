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

int					draw_pixel(int x, int y, t_color *color)
{
	int				fail;

	if (get_sdl_data()->renderer == NULL)
		return (0);
	fail = SDL_SetRenderDrawColor(get_sdl_data()->renderer,
	color->r, color->g, color->b, 255)
	|| SDL_RenderDrawPoint(get_sdl_data()->renderer, x, y);
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

int					draw_img(t_img *img)
{
	int		x;
	int		y;
	double	scale_x;
	double	scale_y;

	SDL_GL_GetDrawableSize(get_sdl_data()->window,
	&get_sdl_data()->width,
	&get_sdl_data()->height);
	scale_x = (double)img->width / (double)get_sdl_data()->width;
	scale_y = (double)img->height / (double)get_sdl_data()->height;
	y = 0;
	while (y < get_sdl_data()->height)
	{
		x = 0;
		while (x < get_sdl_data()->width)
		{
			draw_pixel(x, y, &img->pixel[(int)(x*scale_x)][(int)(y*scale_y)]);
			x++;
		}
		y++;
	}
	return (1);
}
