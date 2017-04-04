#include <rt.h>

void				handle_events(void)
{
	SDL_Event	event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			exit(0);
		}
		else if (event.type == SDL_KEYUP)
		{
			if (event.key.keysym.sym == SDLK_ESCAPE)
				exit(0);
			else if (event.key.keysym.sym == SDLK_a)
				get_sdl_data()->aa = !get_sdl_data()->aa;
		}
	}
}
