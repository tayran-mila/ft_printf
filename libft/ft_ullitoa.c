/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ullitoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 19:21:46 by tmendes-          #+#    #+#             */
/*   Updated: 2020/07/27 19:20:59 by tmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char			*ft_ullitoa(t_ullint n, int base, char sz)
{
	char	*p;
	int		k;
	int		size;

	size = ft_ull_nbrdigit(n, base);
	if (!(p = (char *)malloc((size + 1) * sizeof(char))))
		return (NULL);
	*(p + size) = 0;
	k = size - 1;
	while (k >= 0)
	{
		p[k] = change_base((n % base), sz);
		n = n / base;
		k--;
	}
	return (p);
}
