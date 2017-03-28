/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaize <mlaize@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:30:08 by mlaize            #+#    #+#             */
/*   Updated: 2014/01/24 11:39:29 by mlaize           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int chara, size_t length)
{
	char	*destb;
	char	*srcb;
	int		i;

	destb = (char *)dest;
	srcb = (char *)src;
	i = 0;
	while ((size_t)i < length && srcb[i] != chara)
	{
		destb[i] = srcb[i];
		i++;
	}
	if (srcb[i] == (char)chara)
	{
		destb[i] = srcb[i];
		return ((void *)&(destb[i + 1]));
	}
	else
		return (NULL);
}
