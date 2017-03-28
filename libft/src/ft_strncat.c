/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaize <mlaize@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 14:17:36 by mlaize            #+#    #+#             */
/*   Updated: 2013/11/27 18:04:24 by mlaize           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		offset;
	size_t	i;

	offset = ft_strlen(s1);
	i = 0;
	while (s2[i] && i < n)
	{
		s1[offset + i] = s2[i];
		i++;
	}
	s1[offset + i] = 0;
	return (s1);
}
