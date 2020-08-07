/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversions_01_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 08:20:06 by tmendes-          #+#    #+#             */
/*   Updated: 2020/08/07 08:56:51 by tmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

t_printf			format_nbr(t_printf ptf, t_fields fld)
{
	if (fld.prec_s)
	{
		fld.flag[3] += 1;
		ptf.txt = pad_str(ptf.txt, fld, fld.prec, 'p');
		fld.flag[3] = 0;
	}
	if (*ptf.end == 'x' || *ptf.end == 'X' || *ptf.end == 'o')
	{
		if (fld.flag[3])
		{
			ptf.txt = pad_str(ptf.txt, fld,
			(fld.width - ft_strlen(fld.str)), 'w');
			fld.str = ft_concat(fld.str, ptf.txt);
		}
		else
		{
			fld.str = ft_concat(fld.str, ptf.txt);
			fld.str = pad_str(fld.str, fld, fld.width, 'w');
		}
		free(ptf.txt);
		ptf.txt = fld.str;
	}
	else
		ptf.txt = pad_str(ptf.txt, fld, fld.width, 'w');
	return (ptf);
}

t_fields			fld_process(t_printf ptf, t_fields fld)
{
	if (fld.width < 0)
		fld.flag[4] += 1;
	fld.width = ft_abs(fld.width);
	if (fld.prec < 0 || fld.prec_s < 0)
		fld.prec_s = 0;
	if (*ptf.end == 'd' || *ptf.end == 'i')
		if (fld.prec == 0 && (int)fld.llint == 0)
			*ptf.txt = 0;
	if (*ptf.end == 'x' || *ptf.end == 'X' ||
	*ptf.end == 'u' || *ptf.end == 'o')
		if (fld.prec == 0 && (int)fld.ullint == 0)
			*ptf.txt = 0;
	return (fld);
}

t_printf			d____type(t_printf ptf, t_fields fld, va_list ap)
{
	fld.llint = va_arg(ap, t_llint);
	if (fld.len_h == 2)
		ptf.txt = ft_llitoa((signed char)fld.llint, 10, 'a');
	else if (fld.len_h == 1)
		ptf.txt = ft_llitoa((short int)fld.llint, 10, 'a');
	else if (fld.len_l == 1)
		ptf.txt = ft_llitoa((long int)fld.llint, 10, 'a');
	else if (fld.len_l == 2)
		ptf.txt = ft_llitoa((long long int)fld.llint, 10, 'a');
	else
		ptf.txt = ft_llitoa((int)fld.llint, 10, 'a');
	fld = fld_process(ptf, fld);
	ptf.txt = signal_space(ptf.txt, fld);
	ptf = format_nbr(ptf, fld);
	return (ptf);
}

t_printf			u____type(t_printf ptf, t_fields fld, va_list ap)
{
	fld.ullint = va_arg(ap, t_ullint);
	if (fld.len_h == 2)
		ptf.txt = ft_ullitoa((unsigned char)fld.ullint, 10, 'a');
	else if (fld.len_h == 1)
		ptf.txt = ft_ullitoa((unsigned short)fld.ullint, 10, 'a');
	else if (fld.len_l == 1)
		ptf.txt = ft_ullitoa((unsigned long)fld.ullint, 10, 'a');
	else if (fld.len_l == 2)
		ptf.txt = ft_ullitoa((unsigned long long)fld.ullint, 10, 'a');
	else
		ptf.txt = ft_ullitoa((unsigned int)fld.ullint, 10, 'a');
	fld = fld_process(ptf, fld);
	ptf.txt = signal_space(ptf.txt, fld);
	ptf = format_nbr(ptf, fld);
	return (ptf);
}

t_printf			x____type(t_printf ptf, t_fields fld, va_list ap)
{
	fld.ullint = va_arg(ap, t_ullint);
	if (fld.len_h == 2)
		ptf.txt = ft_ullitoa((unsigned char)fld.ullint, 16, *ptf.end);
	else if (fld.len_h == 1)
		ptf.txt = ft_ullitoa((unsigned short)fld.ullint, 16, *ptf.end);
	else if (fld.len_l == 1)
		ptf.txt = ft_ullitoa((unsigned long)fld.ullint, 16, *ptf.end);
	else if (fld.len_l == 2)
		ptf.txt = ft_ullitoa((unsigned long long)fld.ullint, 16, *ptf.end);
	else
		ptf.txt = ft_ullitoa((unsigned int)fld.ullint, 16, *ptf.end);
	if (fld.flag[0] && (int)fld.ullint)
	{
		fld.str = ft_strdup("0 ");
		*(fld.str + 1) = *ptf.end;
	}
	else
		fld.str = ft_strdup("");
	fld = fld_process(ptf, fld);
	ptf.txt = signal_space(ptf.txt, fld);
	ptf = format_nbr(ptf, fld);
	return (ptf);
}
