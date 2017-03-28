/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isreadable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaize <mlaize@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 14:54:34 by mlaize            #+#    #+#             */
/*   Updated: 2013/11/29 15:22:49 by mlaize           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isreadable(void *s, size_t size)
{
	char			*str;
	unsigned int	i;

	str = (char *)s;
	i = 0;
	while (i < size && ft_isprint(str[i]))
		i++;
	if (!str[i] && i == size - 1)
		return (1);
	else
		return (0);
}
