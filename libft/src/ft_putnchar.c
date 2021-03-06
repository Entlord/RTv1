/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaize <mlaize@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 15:36:58 by mlaize            #+#    #+#             */
/*   Updated: 2014/03/09 22:29:22 by mlaize           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnchar(char c, int nb)
{
	int	i;

	if (nb < 0)
		return ;
	i = 0;
	while (i++ < nb)
		ft_putchar(c);
}
