#ifndef __SCREEN_H__
# define __SCREEN_H__

# include <SDL.h>
# define TITLE "RTV1"

typedef struct		s_sdl_data
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
}					t_sdl_data;

typedef struct		s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;

int					init_window(int width, int height);
int					free_resources(void);
int					clear_image(void);
int					draw_pixel(int x, int y, t_color *color);
int					copy_image_to_window(void);
int					set_color(int r, int g, int b);

#endif
