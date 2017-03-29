/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaize <mlaize@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 13:08:08 by mlaize            #+#    #+#             */
/*   Updated: 2014/02/01 16:01:35 by mlaize           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_pow(int n, int pow)
{
	long	i;
	long	total;

	i = 0;
	total = 1;
	while (i < pow)
	{
		total = total * n;
		i++;
	}
	return (total);
}