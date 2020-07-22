/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 15:23:40 by tmendes-          #+#    #+#             */
/*   Updated: 2020/03/07 17:20:23 by tmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*node_old;
	t_list	*node_new;

	if (lst == NULL || f == NULL)
		return (NULL);
	if (!(head = ft_lstnew(f(lst->content))))
		return (NULL);
	node_old = lst;
	node_new = head;
	while (node_old->next != NULL)
	{
		if (!(node_new->next = ft_lstnew(f(node_old->next->content))))
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		node_new = node_new->next;
		node_old = node_old->next;
	}
	return (head);
}
