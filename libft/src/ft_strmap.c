/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaize <mlaize@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 15:46:15 by mlaize            #+#    #+#             */
/*   Updated: 2013/11/28 11:18:10 by mlaize           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		size;
	int		i;
	char	*newstr;

	size = 0;
	i = 0;
	size = ft_strlen(s);
	newstr = (char *)malloc(size);
	while (i < size)
	{
		newstr[i] = f(s[i]);
		i++;
	}
	return (newstr);
}
