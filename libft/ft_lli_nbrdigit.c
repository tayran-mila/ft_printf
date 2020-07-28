/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lli_nbrdigit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 08:56:32 by tmendes-          #+#    #+#             */
/*   Updated: 2020/07/28 14:42:07 by tmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lli_nbrdigit(t_llint nbr, t_llint base)
{
	int			dig;

	if (nbr > 0)
		nbr = -nbr;
	dig = 0;
	while (nbr <= -1)
	{
		dig++;
		nbr = (nbr / base);
	}
	if (dig == 0)
		dig++;
	return (dig);
}
