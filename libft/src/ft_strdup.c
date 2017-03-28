/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaize <mlaize@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 09:38:00 by mlaize            #+#    #+#             */
/*   Updated: 2013/11/26 13:54:11 by mlaize           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*str2;

	str2 = (char *)malloc(ft_strlen(str) + 1);
	if (str2 == NULL)
		return (NULL);
	ft_strcpy(str2, str);
	return (str2);
}
