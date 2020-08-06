/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversions_03.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 08:20:06 by tmendes-          #+#    #+#             */
/*   Updated: 2020/08/06 08:12:03 by tmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char				*unpad(char *nbr, char chr)
{
	int		k;
	char	*exp;

	exp = ft_strchr(nbr, 'e');
	k = ft_strlen(nbr) - 1;
	if (chr == 'e')
	{
		k -= ft_strlen(exp);
		while ((*(nbr + k) == '0' || *(nbr + k) == '.') &&
		k > 0 && *(nbr + (k - 1)) != '-')
			k--;
		ft_memmove((nbr + k + 1), exp, ft_strlen(exp) + 1);
	}
	else
	{
		while (*(nbr + k) == '0' && k > 0 && *(nbr + (k - 1)) != '-')
			k--;
		if (*(nbr + k) == '.')
			*(nbr + k) = 0;
		*(nbr + k + 1) = 0;
	}
	return (nbr);
}

t_printf			f____type(t_printf ptf, t_fields fld, va_list ap)
{
	if (fld.width < 0)
		fld.flag[4] += 1;
	fld.width = ft_abs(fld.width);
	if (fld.prec < 0)
		fld.prec = 6;
	fld.flt = (long double)va_arg(ap, double);
	ptf.txt = ft_ftoa(fld.flt, fld.prec, 'r');
	if (fld.prec == 0 && fld.flag[0] == 0)
		ptf.txt = unpad(ptf.txt, 'f');
	ptf.txt = signal_space(ptf.txt, fld);
	ptf.txt = pad_str(ptf.txt, fld, fld.width, 'w');
	return (ptf);
}

t_printf			n____type(t_printf ptf, t_fields fld, va_list ap)
{
	if (fld.len_h == 2)
		*va_arg(ap, signed char *) = (signed char)ft_strlen(ptf.final);
	else if (fld.len_h == 1)
		*va_arg(ap, short int *) = (short int)ft_strlen(ptf.final);
	else if (fld.len_l == 2)
		*va_arg(ap, long int *) = (long int)ft_strlen(ptf.final);
	else if (fld.len_l == 1)
		*va_arg(ap, long long int *) = (long long int)ft_strlen(ptf.final);
	else
		*va_arg(ap, int *) = (int)ft_strlen(ptf.final);
	ptf.txt = ft_strdup("");
	return (ptf);
}
