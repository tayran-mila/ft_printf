/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 19:21:46 by tmendes-          #+#    #+#             */
/*   Updated: 2020/07/02 08:42:37 by tmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	pot_10(int nbr)
{
	int pot;

	if (nbr <= 0)
		pot = 1;
	else
		pot = 10 * pot_10(nbr - 1);
	return (pot);
}

static int	m_size(int nbr)
{
	int dig;
	int	n_aux;

	n_aux = nbr;
	if (nbr > 0)
		nbr = -nbr;
	dig = 1;
	if (nbr <= -1)
		while (nbr / 10 <= -pot_10(dig - 1))
			dig++;
	if (n_aux < 0)
		return (dig + 2);
	return (dig + 1);
}

char		*ft_itoa(int n)
{
	char	*p;
	int		k;
	int		size;

	size = m_size(n);
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
		p[k] = (-(n / pot_10(size - k - 2)) % 10) + '0';
		k++;
	}
	p[k] = 0;
	return (p);
}
