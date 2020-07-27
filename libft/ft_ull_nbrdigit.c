/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ull_nbrdigit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 08:56:32 by tmendes-          #+#    #+#             */
/*   Updated: 2020/07/27 19:21:09 by tmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ull_nbrdigit(t_ullint nbr, t_ullint base)
{
	int			dig;

	dig = 0;
	while (nbr >= 1)
	{
		dig++;
		nbr = (nbr / base);
	}
	if (dig == 0)
		dig++;
	return (dig);
}
