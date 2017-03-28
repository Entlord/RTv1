/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaize <mlaize@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 17:29:29 by mlaize            #+#    #+#             */
/*   Updated: 2013/11/27 18:11:09 by mlaize           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int	offset;
	unsigned int	i;

	offset = 0;
	if (s2 == 0 || s1 == 0)
		return (NULL);
	if (s2[0] == 0)
		return ((char *)s1);
	while (s1[offset] && offset < n)
	{
		i = 0;
		while (s1[offset + i] == s2[i] && (offset + i) < n)
		{
			if (!s2[i + 1])
				return ((char *)(s1 + offset));
			i++;
		}
		offset++;
	}
	return (NULL);
}
