/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaize <mlaize@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 11:25:33 by mlaize            #+#    #+#             */
/*   Updated: 2014/04/25 16:49:06 by mlaize           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_atoi_ignored(char c)
{
	if (c == '\n'
			|| c == '\v'
			|| c == '\t'
			|| c == '\r'
			|| c == '\f'
			|| c == ' ')
		return (1);
	else
		return (0);
}

int			ft_atoi(const char *str)
{
	unsigned int	result;
	int				i;

	result = 0;
	i = 0;
	while (is_atoi_ignored(*str))
		str++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (str[0] == '-')
		return (-result);
	return (result);
}
