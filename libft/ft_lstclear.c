/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 13:45:14 by tmendes-          #+#    #+#             */
/*   Updated: 2020/03/07 15:05:14 by tmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*node;
	t_list	*clear;

	if (lst != NULL && del != NULL)
	{
		node = *lst;
		while (node != NULL)
		{
			clear = node;
			node = node->next;
			del(clear->content);
			free(clear);
		}
		*lst = NULL;
	}
}
