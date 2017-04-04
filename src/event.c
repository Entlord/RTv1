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
	}
}
