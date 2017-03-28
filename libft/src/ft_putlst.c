/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaize <mlaize@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 14:41:32 by mlaize            #+#    #+#             */
/*   Updated: 2014/01/07 11:36:27 by mlaize           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putlst(t_list *lst)
{
	int	i;

	i = 0;
	while (1)
	{
		ft_putstr("lst[");
		ft_putstr(ft_itoa(i));
		ft_putstr("] : ");
		if (ft_isreadable(lst->content, lst->content_size))
			ft_putstr(lst->content);
		else
			ft_putnbr(*(int *)lst->content);
		ft_putstr("   /  size = ");
		ft_putnbr(lst->content_size);
		ft_putchar('\n');
		if (lst->next == NULL)
			return ;
		else
			lst = lst->next;
		i++;
	}
}
