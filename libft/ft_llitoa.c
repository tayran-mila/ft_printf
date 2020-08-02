/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 19:21:46 by tmendes-          #+#    #+#             */
/*   Updated: 2020/08/02 14:47:19 by tmendes-         ###   ########.fr       */
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

char			*ft_llitoa(t_llint n, int base, char sz)
{
	char	*p;
	int		k;
	int		size;

	size = ft_lli_nbrdigit(n, base);
	if (!(p = (char *)calloc((size + 2), sizeof(char))))
		return (NULL);
	k = size;
	if ((int)n < 0)
		*p = '-';
	else
	{
		n = -n;
		k--;
	}
	while (k >= 0 && *(p + k) != '-')
	{
		*(p + k) = change_base(-(n % base), sz);
		n = (n / base);
		k--;
	}
	return (p);
}
