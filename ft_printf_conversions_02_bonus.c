/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversions_02_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 08:20:06 by tmendes-          #+#    #+#             */
/*   Updated: 2020/08/07 08:15:46 by tmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

static char			*ld_signal(long double flt)
{
	char	*str;

	if ((1 / flt) < 0)
		str = ft_strdup("-");
	else
		str = ft_strdup("");
	return (str);
}

t_printf			e____type(t_printf ptf, t_fields fld, va_list ap)
{
	if (fld.width < 0)
		fld.flag[4] += 1;
	fld.width = ft_abs(fld.width);
	if (fld.prec < 0)
		fld.prec = 6;
	fld.flt = (long double)va_arg(ap, double);
	fld.itg = nbr_exp(fld.flt, fld.prec);
	ptf.txt = ld_signal(fld.flt);
	fld.flt = ft_ldabs(fld.flt);
	if (fld.prec >= fld.itg)
		fld.str = ft_ftoa(fld.flt, (fld.prec - fld.itg), 'r');
	else
		fld.str = ft_ftoa(fld.flt, 1, 0);
	fld.str = scntfc_not(fld.str, fld.prec);
	ptf.txt = ft_concat(ptf.txt, fld.str);
	free(fld.str);
	fld.str = NULL;
	if (fld.prec == 0 && fld.flag[0] == 0)
		ptf.txt = unpad(ptf.txt, 'e');
	ptf.txt = signal_space(ptf.txt, fld);
	ptf.txt = pad_str(ptf.txt, fld, fld.width, 'w');
	return (ptf);
}

static t_printf		g_aux(t_printf ptf, t_fields fld)
{
	fld.itg = nbr_exp(fld.flt, fld.prec);
	*ptf.end = 'e';
	ptf.txt = ld_signal(fld.flt);
	fld.flt = ft_ldabs(fld.flt);
	if (fld.prec >= (fld.itg + 1))
		fld.str = ft_ftoa(fld.flt, (fld.prec - fld.itg - 1), 'r');
	else
		fld.str = ft_ftoa(fld.flt, 1, 0);
	fld.str = scntfc_not(fld.str, fld.prec - 1);
	if (fld.flag[0] == 0)
		fld.str = unpad(fld.str, *ptf.end);
	ptf.txt = ft_concat(ptf.txt, fld.str);
	free(fld.str);
	fld.str = NULL;
	return (ptf);
}

t_printf			g____type(t_printf ptf, t_fields fld, va_list ap)
{
	if (fld.prec == 0)
		fld.prec++;
	if (fld.width < 0)
		fld.flag[4] += 1;
	fld.width = ft_abs(fld.width);
	if (fld.prec < 0)
		fld.prec = 6;
	fld.flt = (long double)va_arg(ap, double);
	fld.itg = nbr_exp(fld.flt, fld.prec);
	fld.itg = nbr_exp((fld.flt + 5 *
	(ft_ldabs(fld.flt) / fld.flt) *
	ft_ld_pot_b(10, (fld.itg - fld.prec))), fld.prec);
	if (fld.itg < -4 || fld.itg >= fld.prec)
		ptf = g_aux(ptf, fld);
	else
		ptf.txt = ft_ftoa(fld.flt, fld.prec - (fld.itg + 1), 'r');
	if (fld.flag[0] == 0 && *ptf.end != 'e')
		ptf.txt = unpad(ptf.txt, 'f');
	ptf.txt = signal_space(ptf.txt, fld);
	ptf.txt = pad_str(ptf.txt, fld, fld.width, 'w');
	return (ptf);
}
