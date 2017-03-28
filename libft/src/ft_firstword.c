/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_firstword.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaize <mlaize@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 11:36:47 by mlaize            #+#    #+#             */
/*   Updated: 2014/01/07 11:36:49 by mlaize           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_first_word(char *str)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != ' ')
		i++;
	tmp = (char *)malloc(i + 1);
	ft_strncpy(tmp, str, i);
	return (tmp);
}
