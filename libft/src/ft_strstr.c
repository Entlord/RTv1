/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaize <mlaize@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 16:47:00 by mlaize            #+#    #+#             */
/*   Updated: 2014/01/21 18:26:41 by mlaize           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	unsigned int	offset;
	unsigned int	i;

	offset = 0;
	if (!*s2)
		return ((char *)s1);
	while (s1[offset])
	{
		i = 0;
		while (s1[offset + i] == s2[i])
		{
			if (!s2[i + 1])
				return ((char *)(s1 + offset));
			i++;
		}
		offset++;
	}
	return (NULL);
}
