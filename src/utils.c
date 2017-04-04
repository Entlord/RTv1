#include <rt.h>

t_color	get_color(int r, int g, int b)
{
	t_color	color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

t_color	*cpy_pixel(t_color *src, t_color *dest)
{
	dest->r = src->r;
	dest->g = src->g;
	dest->b = src->b;
	return (dest);
}