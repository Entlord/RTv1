#include <rt.h>

t_ball				*new_ball(void)
{
	return (ft_memalloc(sizeof(t_ball) + 1));
}

t_tube				*new_tube(void)
{
	return (ft_memalloc(sizeof(t_tube) + 1));
}

t_cone				*new_cone(void)
{
	return (ft_memalloc(sizeof(t_cone) + 1));
}

t_plan				*new_plan(void)
{
	return (ft_memalloc(sizeof(t_plan) + 1));
}

t_object			*new_box(void)
{
	return (ft_memalloc(sizeof(t_box) + 1));
}