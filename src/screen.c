#include <rt.h>

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

t_color				get_average_pixel(t_img *img, int x, int y)
{
	t_color	average;
	double	scale_x;
	double	scale_y;

	scale_x = (double)img->width / (double)get_sdl_data()->width;
	scale_y = (double)img->height / (double)get_sdl_data()->height;
	average.r = (img->pixel[(int)(x*scale_x)][(int)(y*scale_y)].r / 2.0
	+ img->pixel[(int)((x+1.0)*scale_x)][(int)((y+1.0)*scale_y)].r / 2.0);
	average.g = (img->pixel[(int)(x*scale_x)][(int)(y*scale_y)].g / 2.0
	+ img->pixel[(int)((x+1.0)*scale_x)][(int)((y+1.0)*scale_y)].g / 2.0);
	average.b = (img->pixel[(int)(x*scale_x)][(int)(y*scale_y)].b / 2.0
	+ img->pixel[(int)((x+1.0)*scale_x)][(int)((y+1.0)*scale_y)].b / 2.0);
	return (average);
}

t_color				get_pixel(t_img *img, int x, int y)
{
	t_color	average;
	double	scale_x;
	double	scale_y;

	scale_x = (double)img->width / (double)get_sdl_data()->width;
	scale_y = (double)img->height / (double)get_sdl_data()->height;
	average.r = (img->pixel[(int)(x*scale_x)][(int)(y*scale_y)].r);
	average.g = (img->pixel[(int)(x*scale_x)][(int)(y*scale_y)].g);
	average.b = (img->pixel[(int)(x*scale_x)][(int)(y*scale_y)].b);
	return (average);
}

int					draw_img(t_img *img)
{
	int		x;
	int		y;
	t_color	average;

	SDL_GL_GetDrawableSize(get_sdl_data()->window,
	&get_sdl_data()->width,
	&get_sdl_data()->height);
	y = 0;
	while (y + 1 < get_sdl_data()->height)
	{
		x = 0;
		while (x + 1 < get_sdl_data()->width)
		{
			average = get_sdl_data()->aa ?
			get_average_pixel(img, x, y) : get_pixel(img, x, y);
			draw_pixel(x, y, &average);
			x++;
		}
		y++;
	}
	return (1);
}
