/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 08:20:06 by tmendes-          #+#    #+#             */
/*   Updated: 2020/07/26 10:53:12 by tmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static long int *hold_null(long int * p_int, int pos)
{
	long int	*p_aux;
	long int	k;

	k = 0;
	p_aux = p_int;
	if (!p_int)
	{
		if(!(p_int = (long int *)malloc(2 * sizeof(long int))))
			return (NULL);
		*p_int = pos;
		*(p_int + 1) = -1;
	}
	else
	{
		while (*(p_int + k) != -1)
			k++;
		if (!(p_int = (long int *)malloc((k + 2) * sizeof(long int))))
			return (NULL);
		*(p_int + k + 1) = -1;
		*(p_int + k) = pos;
		while (--k >= 0)
			*(p_int + k) = *(p_aux + k);
		free(p_aux);
	}
	return (p_int);
}

t_printf	c_or_s(t_printf ptf, t_fields fld, va_list ap)
{
	if (*ptf.end == 'c')
	{
		if (fld.width < 0)
			fld.flag[4] += 1;
		fld.width = ft_abs(fld.width);
		ptf.txt = ft_strdup(" ");
		if (fld.len_l == 1)
			*ptf.txt = (char)va_arg(ap, wint_t);
		else
			*ptf.txt = (char)va_arg(ap, int);
		if (*ptf.txt == 0)
		{
			*ptf.txt = 1;
			ptf.txt = pad_str(ptf.txt, fld, fld.width, 'w');
			fld.itg = 0;
			while (*(ptf.txt + fld.itg) != 1)
				fld.itg++;
			ptf.pstn = hold_null(ptf.pstn, ft_strlen(ptf.final) + fld.itg);
		}
		else
			ptf.txt = pad_str(ptf.txt, fld, fld.width, 'w');
	}
	if (*ptf.end == 's')
	{
		if (fld.width < 0)
			fld.flag[4] += 1;
		fld.width = ft_abs(fld.width);
		if (fld.len_l == 1)
			fld.str = (char *)va_arg(ap, wchar_t *);
		else
			fld.str = va_arg(ap, char *);
		if (fld.prec < 0 || fld.prec_s < 0)
			fld.prec_s = 0;
		if (fld.str)
			ptf.txt = ft_strdup((char *)fld.str);
		else
			ptf.txt = ft_strdup("(null)");
		fld.str = NULL;
		if (fld.prec < (int)ft_strlen(ptf.txt) && fld.prec_s)
			*(ptf.txt + fld.prec) = 0;
		ptf.txt = pad_str(ptf.txt, fld, fld.width, 'w');
	}
	return (ptf);
}

t_printf	p_or_d_or_i(t_printf ptf, t_fields fld, va_list ap)
{
	if (*ptf.end == 'p')
	{
		if (fld.width < 0)
			fld.flag[4] += 1;
		fld.width = ft_abs(fld.width);
		fld.ptr = va_arg(ap, void *);
		ptf.txt = ft_strdup("0x");	
		fld.str = ft_llitoa((unsigned long int)fld.ptr, 16, 'a');

		if (fld.prec < 0 || fld.prec_s < 0)
			fld.prec_s = 0;
		if (fld.prec == 0 && *ptf.txt == '0')
			*fld.str = 0;
		if (fld.prec_s)
		{
			fld.flag[3] += 1;
			fld.str = pad_str(fld.str, fld, fld.prec, 'p');
			fld.flag[3] = 0;
		}

		ptf.txt = ft_concat(ptf.txt, fld.str);
		free(fld.str);
		fld.str = NULL;
		ptf.txt = pad_str(ptf.txt, fld, fld.width, 'w');

	}
	if (*ptf.end == 'd' || *ptf.end == 'i')
	{
		if (fld.width < 0)
			fld.flag[4] += 1;
		fld.width = ft_abs(fld.width);
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
		if (fld.prec < 0 || fld.prec_s < 0)
			fld.prec_s = 0;
		if (fld.prec == 0 && *ptf.txt == '0')
			*ptf.txt = 0;
		if (fld.prec_s)
		{
			fld.flag[3] += 1;
			ptf.txt = pad_str(ptf.txt, fld, fld.prec, 'p');
			fld.flag[3] = 0;
		}
		ptf.txt = pad_str(ptf.txt, fld, fld.width, 'w');
	}
	return (ptf);
}

t_printf	u_or_p100(t_printf ptf, t_fields fld, va_list ap)
{
	if (*ptf.end == 'u')
	{
		if (fld.width < 0)
			fld.flag[4] += 1;
		fld.width = ft_abs(fld.width);
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
		ptf.txt = signal_space(ptf.txt, fld);
		if (fld.prec < 0 || fld.prec_s < 0)
			fld.prec_s = 0;
		if (fld.prec == 0 && *ptf.txt == '0')
			*ptf.txt = 0;
		if (fld.prec_s)
		{
			fld.flag[3] += 1;
			ptf.txt = pad_str(ptf.txt, fld, fld.prec, 'p');
			fld.flag[3] = 0;
		}
		ptf.txt = pad_str(ptf.txt, fld, fld.width, 'w');
	}
	if (*ptf.end == '%')
	{
		if (fld.width < 0)
			fld.flag[4] += 1;
		fld.width = ft_abs(fld.width);
		ptf.txt = ft_strdup("%");
		ptf.txt = pad_str(ptf.txt, fld, fld.width, 'w');
	}
	return (ptf);
}

t_printf	x_decimal(t_printf ptf, t_fields fld, va_list ap)
{
	if (fld.width < 0)
			fld.flag[4] += 1;
		fld.width = ft_abs(fld.width);
	if (fld.flag[0])
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
		fld.str = ft_llitoa(va_arg(ap, unsigned int), 16, *ptf.end);
	ptf.txt = ft_concat(ptf.txt, fld.str);
	free(fld.str);
	fld.str = NULL;
	ptf.txt = signal_space(ptf.txt, fld);
	if (fld.prec < 0 || fld.prec_s < 0)
			fld.prec_s = 0;
	if (fld.prec == 0 && *ptf.txt == '0')
			*ptf.txt = 0;
		if (fld.prec_s)
		{
			fld.flag[3] += 1;
			ptf.txt = pad_str(ptf.txt, fld, fld.prec, 'p');
			fld.flag[3] = 0;
		}
	ptf.txt = pad_str(ptf.txt, fld, fld.width, 'w');
	return (ptf);
}
