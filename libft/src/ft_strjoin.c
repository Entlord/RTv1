/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaize <mlaize@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 18:14:34 by mlaize            #+#    #+#             */
/*   Updated: 2013/11/26 11:10:38 by mlaize           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	len1;
	unsigned int	len2;
	unsigned int	i;
	char			*str;

	len1 = 0;
	len2 = 0;
	i = 0;
	while (s1[len1])
		len1++;
	while (s2[len2])
		len2++;
	str = (char *)malloc(len1 + len2 + 1);
	while (i < len1)
	{
		str[i] = s1[i];
		i++;
	}
	while (i < (len1 + len2))
	{
		str[i] = s2[i - len1];
		i++;
	}
	str[i] = 0;
	return (str);
}
