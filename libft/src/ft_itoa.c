/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaize <mlaize@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 14:25:49 by mlaize            #+#    #+#             */
/*   Updated: 2014/01/24 15:17:14 by mlaize           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int m)
{
	int		len;
	int		i;
	int		neg;
	char	*str;
	long	n;

	n = m;
	len = 1;
	i = 0;
	neg = (n < 0) ? 1 : 0;
	n = (n < 0) ? -n : n;
	while (ft_pow(10, len) <= n)
		len++;
	str = (char *)ft_strnew(len + 1);
	if (neg)
		str[i++] = '-';
	while (len > 0)
	{
		str[i] = (n / ft_pow(10, len - 1)) % 10 + '0';
		i++;
		len--;
	}
	return (str);
}
