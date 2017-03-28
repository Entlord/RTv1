/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaize <mlaize@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 18:25:33 by mlaize            #+#    #+#             */
/*   Updated: 2013/11/30 16:51:10 by mlaize           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*mylink;
	t_list	*linkcopy;

	mylink = (t_list *)malloc(sizeof(t_list *));
	if (lst->next != NULL)
	{
		mylink->next = ft_lstmap(lst->next, f);
	}
	linkcopy = f(lst);
	mylink->content = linkcopy->content;
	mylink->content_size = linkcopy->content_size;
	return (mylink);
}
