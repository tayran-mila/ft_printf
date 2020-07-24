/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 08:56:32 by tmendes-          #+#    #+#             */
/*   Updated: 2020/07/23 12:11:26 by tmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbrdigit(long double nbr)
{
	int			dig;

	if (nbr < 0)
		nbr = -nbr;
	dig = 0;
	while (nbr >= 1)
	{
		dig++;
		nbr = (nbr / 10);
	}
	if (dig == 0)
		dig++;
	return (dig);
}
