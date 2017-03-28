/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strealloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaize <mlaize@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 14:53:09 by mlaize            #+#    #+#             */
/*   Updated: 2014/01/21 12:47:44 by mlaize           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strealloc(char **str, size_t size)
{
	char	*newstr;
	size_t	sizebefore;

	sizebefore = 0;
	if (*str != NULL)
		sizebefore = ft_strlen(*str) + 1;
	newstr = ft_strnew(sizebefore + size);
	if (newstr == NULL)
		return (NULL);
	if (*str != NULL)
	{
		ft_strcpy(newstr, *str);
		free(*str);
	}
	*str = newstr;
	return (newstr);
}
