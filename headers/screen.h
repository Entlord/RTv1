#ifndef __SCREEN_H__
# define __SCREEN_H__

# include <SDL.h>
# include "struct.h"
# define TITLE "RTV1"

typedef struct		s_sdl_data
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	int				width;
	int				height;
}					t_sdl_data;

int					init_window(int width, int height);
int					free_resources(void);
int					clear_image(void);
int					draw_pixel(int x, int y, t_color *color);
int					draw_img(t_img *img);
int					refresh_window(void);
void				handle_events(void);
t_sdl_data			*get_sdl_data(void);

#endif
