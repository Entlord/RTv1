#include <rt.h>

t_list_rt			*new_list_rt(void)
{
	return (ft_memalloc(sizeof(t_list_rt) + 1));
}