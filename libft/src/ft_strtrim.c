/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaize <mlaize@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 18:47:05 by mlaize            #+#    #+#             */
/*   Updated: 2014/03/07 19:26:56 by mlaize           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strtrim_isillegal(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	else
		return (0);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	int		offset;
	int		endset;
	int		length;

	offset = 0;
	while (ft_strtrim_isillegal(s[offset]))
		offset++;
	endset = ft_strlen(s) - 1;
	while (ft_strtrim_isillegal(s[endset]))
		endset--;
	if ((endset - offset + 1) < 0)
		length = 0;
	else
		length = endset - offset + 1;
	str = (char *)malloc(length + 1);
	ft_strncpy(str, (s + offset), length);
	str[length] = 0;
	return (str);
}
