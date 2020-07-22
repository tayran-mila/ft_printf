/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 19:21:46 by tmendes-          #+#    #+#             */
/*   Updated: 2020/07/02 12:21:24 by tmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_llint	pot_b(t_llint nbr, int base)
{
	t_llint	pot;

	if (nbr <= 0)
		pot = 1;
	else
		pot = base * pot_b(nbr - 1, base);
	return (pot);
}

static t_llint	m_size(t_llint nbr, int base)
{
	t_llint	dig;
	t_llint	n_aux;

	n_aux = nbr;
	if (nbr > 0)
		nbr = -nbr;
	dig = 1;
	if (nbr <= -1)
		while (nbr / base <= -pot_b(dig - 1, base))
			dig++;
	if (n_aux < 0)
		return (dig + 2);
	return (dig + 1);
}

static char		change_base(int nbr, char sz)
{
	if (nbr >= 0 && nbr <= 9)
		return (nbr + '0');
	if (nbr >= 10 && sz >= 'a' && sz <= 'z')
		return (nbr - 10 + 'a');
	if (nbr >= 10 && sz >= 'A' && sz <= 'Z')
		return (nbr - 10 + 'A');
	return (0);
}

char			*ft_llitoa(t_llint n, int base, char sz)
{
	char		*p;
	t_llint		k;
	t_llint		size;

	size = m_size(n, base);
	if (!(p = (char *)malloc(size * sizeof(char))))
		return (NULL);
	k = 0;
	if (n < 0)
	{
		p[0] = '-';
		k++;
	}
	else
		n = -n;
	while (k <= (size - 2))
	{
		p[k] = change_base((-(n / pot_b(size - k - 2, base)) % base), sz);
		k++;
	}
	p[k] = 0;
	return (p);
}
