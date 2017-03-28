/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaize <mlaize@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 18:11:46 by mlaize            #+#    #+#             */
/*   Updated: 2013/11/30 10:35:12 by mlaize           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*mylink;

	if ((*alst)->next != NULL)
	{
		mylink = (*alst)->next;
		ft_lstdel(&mylink, del);
	}
	ft_lstdelone(alst, del);
	*alst = NULL;
}
