#include <rt.h>

size_t			keyword_file_size(const char *str)
{
	size_t		i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\t' && str[i] != ' ' && str[i] != '\n')
		++i;
	return (i);
}

void			keyword_tolower(char *str, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n)
	{
		str[i] = ft_tolower(str[i]);
		++i;
	}
}

int				keyword_file_check(const char *str, size_t n)
{
	if (!(ft_strncmp(str, "map_name", n)))
		return (MAP_NAME);
	else if (!(ft_strncmp(str, "sphere", n)))
		return (SPHERE);
	else if (!(ft_strncmp(str, "cylinder", n)))
		return (CYLINDER);
	else if (!(ft_strncmp(str, "cone", n)))
		return (CONE);
	else if (!(ft_strncmp(str, "plan", n)))
		return (PLAN);
	else if (!(ft_strncmp(str, "box", n)))
		return (BOX);
	else
		return (ERROR_KEYWORD);
}