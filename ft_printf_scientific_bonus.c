/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_scientific_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 08:30:10 by tmendes-          #+#    #+#             */
/*   Updated: 2020/08/07 08:16:26 by tmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

int					nbr_exp(long double nbr, int prec)
{
	t_llint		nbr_i;
	int			k;

	nbr = ft_ldabs(nbr);
	prec++;
	if (nbr == 0)
		return (0);
	else if (nbr >= 1)
		return ((ft_nbrdigit(nbr) - 1));
	else
	{
		k = 0;
		nbr_i = (t_llint)nbr;
		while (nbr_i == 0)
		{
			k--;
			nbr_i = (t_llint)(10 * nbr);
			nbr = (10 * nbr) - (long double)nbr_i;
		}
		return (k);
	}
}

static char			*p_exp(char *nbr, int prec, t_scntfc sci)
{
	sci.itg = 1;
	while (*(nbr + sci.itg) != '.')
		sci.itg++;
	ft_memmove((nbr + sci.itg), (nbr + sci.itg + 1), prec + 2);
	sci.chr = *(nbr + prec + 2);
	*(nbr + prec + 2) = 0;
	if (sci.chr >= '5' && sci.itg > (prec + 2))
		nbr = ft_strround(nbr);
	if (*nbr == '0')
	{
		nbr = ft_memmove(nbr, (nbr + 1), prec + 2);
		sci.itg--;
	}
	else
		*(nbr + prec + 1) = 0;
	ft_memmove((nbr + 2), (nbr + 1), prec + 1);
	*(nbr + 1) = '.';
	nbr = ft_concat(nbr, "e+");
	sci.itg--;
	if (sci.itg < 10)
		nbr = ft_concat(nbr, "0");
	sci.exp = ft_llitoa(sci.itg, 10, 'a');
	nbr = ft_concat(nbr, sci.exp);
	free(sci.exp);
	return (nbr);
}

static char			*n_exp(char *nbr, int prec, t_scntfc sci)
{
	sci.ptr = ft_strchr(nbr, '.');
	sci.itg = 1;
	while (*(sci.ptr + sci.itg) == '0')
		sci.itg++;
	if (*(sci.ptr + sci.itg) == 0)
	{
		*(nbr + prec + 2) = 0;
		nbr = ft_concat(nbr, "e+00");
		return (nbr);
	}
	nbr = ft_memmove(nbr, (sci.ptr + sci.itg), prec + 2);
	sci.chr = *(nbr + prec + 1);
	*(nbr + prec + 1) = 0;
	ft_memmove((nbr + 2), (nbr + 1), prec + 1);
	*(nbr + 1) = '.';
	nbr = ft_concat(nbr, "e-");
	if (sci.itg < 10)
		nbr = ft_concat(nbr, "0");
	sci.exp = ft_llitoa(sci.itg, 10, 'a');
	nbr = ft_concat(nbr, sci.exp);
	free(sci.exp);
	return (nbr);
}

char				*scntfc_not(char *nbr, int prec)
{
	t_scntfc sci;

	sci = init_scntfc();
	if (*nbr == '0')
		nbr = n_exp(nbr, prec, sci);
	else
	{
		sci.ptr = nbr;
		nbr = ft_strdup("0");
		nbr = ft_concat(nbr, sci.ptr);
		nbr = p_exp(nbr, prec, sci);
		free(sci.ptr);
	}
	sci = init_scntfc();
	return (nbr);
}
