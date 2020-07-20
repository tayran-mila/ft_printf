/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 13:52:39 by tmendes-          #+#    #+#             */
/*   Updated: 2020/07/20 12:58:01 by tmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

char	*join_ptr(char *dst, char *src)
{
	char	*join;

	join = dst;
	if (!(dst = (char *)ft_strjoin(join, src)))
		return (NULL);
	free(join);
	join = NULL;
	return (dst);
}

char *round_str(char *final)
{
	int	k;

	k = ft_strlen(final) - 1;
	while (k >= 0)
	{
		if (*(final + k) == '9')
		{
			*(final + k) = '0';
			k--;
		}
		else
		{
			*(final + k) = *(final + k) + 1;
			return (final);
		}
	}
	return (final);
}

static char *fraction(long double nbr, int dig)
{
	long double	nbr_f;
	t_llint		nbr_i;
	char		*final;
	int			k;

	if(!(final = malloc((dig + 2) * sizeof(char))))
		return (NULL);
	nbr_i = (t_llint)nbr;
	nbr_f = nbr - (long double)nbr_i;
	*final = '0';
	k = 1;
	while (k <= dig + 1)
	{
		nbr_i = (t_llint)(10*nbr_f);
		*(final + k) = nbr_i + '0';
		nbr_f = (10*nbr_f) - (long double)nbr_i;
		k++;
	}
	*(final + dig + 1) = 0;
	if (nbr_i >= 5)
		final = round_str(final);
	return (final);
}

int	nbr_digit(long double nbr)
{
	int			dig;

	if (nbr < 0)
		nbr = -nbr;
	dig = 0;
	while (nbr >= 1)
	{
		dig++;
		nbr = (nbr/10);
	}
	if (dig == 0)
		dig++;
	return (dig);
}

static long double	lpot_b( long double base,  int exp)
{
	long double	pot;

	if (exp <= 0)
		pot = 1;
	else
		pot = base * lpot_b(base, exp - 1);
	return (pot);
}

static char *integer(long double nbr)
{
	long double	nbr_f;
	int			nbr_i;
	char		*final;
	int			dig;
	int			k;

	dig = nbr_digit(nbr);
	if(!(final = malloc((dig + 2) * sizeof(char))))
		return (NULL);
	k = 0;
	*final = '0';
	while (k < dig)
	{
		nbr_f = nbr/lpot_b(10, (dig -1 - k));
		nbr_i = (int)nbr_f;
		*(final + k + 1) = nbr_i + '0';
		nbr = nbr - (long double)(nbr_i * lpot_b(10, (dig -1 - k)));
		k++;
	}
	*(final + k + 1) = 0;
	return (final);
}

char *ft_ftoa(long double nbr, int dig)
{
	char	*final;
	char	*frctn;
	char	*itger;

	if (1/nbr < 0)
	{
		nbr = -nbr;
		final = ft_strdup("-");
	}
	else
		final = ft_strdup("");
	itger = integer(nbr);
	frctn = fraction(nbr, dig);
	if (*frctn == '1')
		itger = round_str(itger);
	if (*itger == '1')
		final = join_ptr(final, itger);
	else
		final = join_ptr(final, (itger + 1));		
	final = join_ptr(final, ".");
	if (!(final = join_ptr(final, (frctn + 1))))
		return (NULL);
	free (frctn);
	free (itger);
	return (final);
}