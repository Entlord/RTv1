#include <rt.h>

t_sdl_data			*get_sdl_data(void)
{
	static t_sdl_data	sdl_data = {
		NULL,
		NULL,
		0,
		0,
		1
	};

	return (&sdl_data);
}
