/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaize <mlaize@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 15:24:32 by mlaize            #+#    #+#             */
/*   Updated: 2013/11/27 14:23:02 by mlaize           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		i;
	size_t	dstlen;

	dstlen = ft_strlen(dst);
	i = 0;
	while ((i + dstlen + 1) < size && src[i])
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = 0;
	if (dstlen < size)
		return (dstlen + ft_strlen(src));
	else
		return (size + ft_strlen(src));
}
