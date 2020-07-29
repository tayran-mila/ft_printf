/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 13:52:39 by tmendes-          #+#    #+#             */
/*   Updated: 2020/07/29 14:39:50 by tmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*integer(long double nbr)
{
	long double	nbr_f;
	int			nbr_i;
	char		*final;
	int			dig;
	int			k;

	dig = ft_nbrdigit(nbr);
	if (!(final = malloc((dig + 2) * sizeof(char))))
		return (NULL);
	k = 0;
	*final = '0';
	while (k < dig)
	{
		nbr_f = nbr / ft_ld_pot_b(10, (dig - 1 - k));
		nbr_i = (int)nbr_f;
		*(final + k + 1) = nbr_i + '0';
		nbr = nbr - (long double)(nbr_i * ft_ld_pot_b(10, (dig - 1 - k)));
		k++;
	}
	*(final + k + 1) = 0;
	return (final);
}

static char		*fraction(long double nbr, int dig, char rnd)
{
	long double	nbr_f;
	t_llint		nbr_i;
	char		*final;
	int			k;

	if (!(final = malloc((dig + 2) * sizeof(char))))
		return (NULL);
	nbr_i = (t_llint)nbr;
	nbr_f = nbr - (long double)nbr_i;
	*final = '0';
	k = 1;
	while (k <= dig + 1)
	{
		nbr_i = (t_llint)(10 * nbr_f);
		*(final + k) = nbr_i + '0';
		nbr_f = (10 * nbr_f) - (long double)nbr_i;
		k++;
	}
	*(final + dig + 1) = 0;
	if (nbr_i >= 5 && rnd == 'r')
		final = ft_strround(final);
	return (final);
}

char			*ft_ftoa(long double nbr, int dig, char rnd)
{
	char	*final;
	char	*frctn;
	char	*itger;

	if ((1 / nbr) < 0)
		final = ft_strdup("-");
	else
		final = ft_strdup("");
	nbr = ft_ldabs(nbr);
	itger = integer(nbr);
	frctn = fraction(nbr, dig, rnd);
	if (((itger[1] - '0') % 2) == 0 && dig == 0 && (nbr - (t_llint)nbr) == 0.5)
		*frctn = '0';
	if (*frctn == '1')
		itger = ft_strround(itger);
	if (*itger == '1')
		final = ft_concat(final, itger);
	else
		final = ft_concat(final, (itger + 1));
	final = ft_concat(final, ".");
	if (!(final = ft_concat(final, (frctn + 1))))
		return (NULL);
	free(frctn);
	free(itger);
	return (final);
}
