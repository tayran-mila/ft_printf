/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 08:20:06 by tmendes-          #+#    #+#             */
/*   Updated: 2020/07/22 08:23:29 by tmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*c_or_s(t_printf ptf, t_fields fld, va_list ap)
{
	if (*ptf.end == 'c')
	{
		ptf.txt = ft_strdup("");
		if (fld.len_l == 1)
			*ptf.txt = (char)va_arg(ap, wint_t);
		else
			*ptf.txt = (char)va_arg(ap, int);
		ptf.txt = pad_str(ptf.txt, fld);
	}
	if (*ptf.end == 's')
	{
		if (fld.len_l == 1)
			ptf.txt = ft_strdup((char *)va_arg(ap, wchar_t *));
		else
			ptf.txt = ft_strdup(va_arg(ap, char *));
		if (fld.prec < (int)ft_strlen(ptf.txt))
			*(ptf.txt + fld.prec) = 0;
		ptf.txt = pad_str(ptf.txt, fld);
	}
	return (ptf.txt);
}

char	*p_or_d_or_i(t_printf ptf, t_fields fld, va_list ap)
{
	if (*ptf.end == 'p')
	{
		ptf.txt = ft_strdup("0x");
		fld.str = ft_llitoa((unsigned long int)va_arg(ap, void *), 16, 'a');
		ptf.txt = ft_concat(ptf.txt, fld.str);
		free(fld.str);
		fld.str = NULL;
		ptf.txt = pad_str(ptf.txt, fld);
	}
	if (*ptf.end == 'd' || *ptf.end == 'i')
	{
		if (fld.len_h == 2)
			ptf.txt = ft_llitoa((signed char)va_arg(ap, int), 10, 'a');
		if (fld.len_h == 1)
			ptf.txt = ft_llitoa((short int)va_arg(ap, int), 10, 'a');
		if (fld.len_l == 2)
			ptf.txt = ft_llitoa(va_arg(ap, long int), 10, 'a');
		if (fld.len_l == 1)
			ptf.txt = ft_llitoa(va_arg(ap, long long int), 10, 'a');
		else
			ptf.txt = ft_llitoa(va_arg(ap, int), 10, 'a');
		ptf.txt = signal_space(ptf.txt, fld);
		ptf.txt = pad_str(ptf.txt, fld);
	}
	return (ptf.txt);
}

char	*u_or_p100(t_printf ptf, t_fields fld, va_list ap)
{
	if (*ptf.end == 'u')
	{
		if (fld.len_h == 2)
			ptf.txt = ft_llitoa((unsigned char)va_arg(ap, int), 10, 'a');
		if (fld.len_h == 1)
			ptf.txt = ft_llitoa((unsigned short int)va_arg(ap, int), 10, 'a');
		if (fld.len_l == 2)
			ptf.txt = ft_llitoa(va_arg(ap, unsigned long int), 10, 'a');
		if (fld.len_l == 1)
			ptf.txt = ft_llitoa(va_arg(ap, unsigned long long int), 10, 'a');
		else
			ptf.txt = ft_llitoa(va_arg(ap, unsigned int), 10, 'a');
		ptf.txt = pad_str(ptf.txt, fld);
	}
	if (*ptf.end == '%')
	{
		if (ptf.begin == ptf.end)
			ptf.txt = ft_strdup("%");
		else
			return (NULL);
	}
	return (ptf.txt);
}

char	*x_decimal(t_printf ptf, t_fields fld, va_list ap)
{
	if ((fld.flag % 10) == 1)
	{
		ptf.txt = ft_strdup("0 ");
		*(ptf.txt + 1) = *ptf.end;
	}
	else
		ptf.txt = ft_strdup("");
	if (fld.len_h == 2)
		fld.str = ft_llitoa((unsigned char)va_arg(ap, int), 16, *ptf.end);
	if (fld.len_h == 1)
		fld.str = ft_llitoa((unsigned short int)va_arg(ap, int), 16, *ptf.end);
	if (fld.len_l == 2)
		fld.str = ft_llitoa(va_arg(ap, unsigned long int), 16, *ptf.end);
	if (fld.len_l == 1)
		fld.str = ft_llitoa(va_arg(ap, unsigned long long int), 16, *ptf.end);
	else
		fld.str = ft_llitoa(va_arg(ap, long long int), 16, *ptf.end);
	ptf.txt = ft_concat(ptf.txt, fld.str);
	free(fld.str);
	fld.str = NULL;
	ptf.txt = signal_space(ptf.txt, fld);
	ptf.txt = pad_str(ptf.txt, fld);
	return (ptf.txt);
}
