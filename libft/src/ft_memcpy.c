/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaize <mlaize@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:51:35 by mlaize            #+#    #+#             */
/*   Updated: 2013/12/31 13:10:52 by mlaize           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t length)
{
	unsigned int	i;
	char			*desti;
	char			*srci;

	i = 0;
	desti = (char *)dest;
	srci = (char *)src;
	while (i < length)
	{
		desti[i] = srci[i];
		i++;
	}
	return (dest);
}
