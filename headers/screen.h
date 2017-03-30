#ifndef __SCREEN_H__
# define __SCREEN_H__

# include <SDL.h>
# include "struct.h"
# define TITLE "RTV1"

typedef struct		s_sdl_data
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
}					t_sdl_data;

int					init_window(int width, int height);
int					free_resources(void);
int					clear_image(void);
int					draw_pixel(int x, int y, t_color *color);
int					draw_img(t_img *img);
int					refresh_window(void);
int					set_color(int r, int g, int b);


#endif
