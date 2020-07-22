/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld_pot_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 09:09:21 by tmendes-          #+#    #+#             */
/*   Updated: 2020/07/22 09:28:17 by tmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long double		ft_ld_pot_b(long double base, int exp)
{
	long double	pot;

	if (exp <= 0)
		pot = 1;
	else
		pot = base * ft_ld_pot_b(base, exp - 1);
	return (pot);
}
