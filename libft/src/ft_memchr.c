/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaize <mlaize@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 13:18:34 by mlaize            #+#    #+#             */
/*   Updated: 2013/11/27 18:12:54 by mlaize           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char			*string;
	unsigned int	i;

	string = (char *)s;
	i = 0;
	while (i < n && string[i] != c)
		i++;
	if (string[i] == c)
		return ((void *)(string + i));
	else
		return (NULL);
}
