/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld_pot_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 09:09:21 by tmendes-          #+#    #+#             */
/*   Updated: 2020/07/29 14:52:28 by tmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long double		ft_ld_pot_b(long double base, int exp)
{
	long double	pot;

	pot = 1;
	if (exp == 0)
		return (pot);
	else if (exp > 0)
		pot = base * ft_ld_pot_b(base, exp - 1);
	else if (exp < 0)
		pot = ft_ld_pot_b(base, exp + 1) / base;
	return (pot);
}
