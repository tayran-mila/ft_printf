/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lli_pot_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 11:56:26 by tmendes-          #+#    #+#             */
/*   Updated: 2020/07/22 09:29:08 by tmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_llint		ft_lli_pot_b(int base, int exp)
{
	t_llint	pot;

	if (exp <= 0)
		pot = 1;
	else
		pot = base * ft_lli_pot_b(base, exp - 1);
	return (pot);
}
