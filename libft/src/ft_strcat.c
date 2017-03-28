/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaize <mlaize@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 17:09:54 by mlaize            #+#    #+#             */
/*   Updated: 2013/11/28 17:11:49 by mlaize           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int	offset;
	int	i;

	offset = ft_strlen(s1);
	i = 0;
	while (s2[i])
	{
		s1[offset + i] = s2[i];
		i++;
	}
	s1[offset + i] = 0;
	return (s1);
}
