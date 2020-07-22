/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 07:17:38 by tmendes-          #+#    #+#             */
/*   Updated: 2020/03/03 07:25:13 by tmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		k;
	t_list	*node;

	k = 0;
	node = lst;
	while (node != NULL)
	{
		k++;
		node = node->next;
	}
	return (k);
}
