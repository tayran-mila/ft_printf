/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 08:20:06 by tmendes-          #+#    #+#             */
/*   Updated: 2020/07/22 08:22:28 by tmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char		*repeat_chr(char chr, int nbr)
{
	char	*str;
	int		k;

	if (!(str = (char *)malloc((nbr + 1) * sizeof(char))))
		return (NULL);
	k = 0;
	while (k < nbr)
	{
		*(str + k) = chr;
		k++;
	}
	*(str + k) = 0;
	return (str);
}

char			*pad_str(char *str, t_fields fld)
{
	fld.itg = fld.width - ft_strlen(str);
	if (fld.itg > 0)
	{
		if (((fld.flag / 10000) % 10))
			fld.str = repeat_chr(' ', fld.itg);
		else
		{
			fld.str = str;
			if (((fld.flag / 1000) % 10))
			{
				str = repeat_chr('0', fld.itg);
				if (*fld.str == '-' || *fld.str == ' ' || *fld.str == '+')
				{
					*str = *fld.str;
					*fld.str = '0';
				}
			}
			else
				str = repeat_chr(' ', fld.itg);
		}
		str = ft_concat(str, fld.str);
		free(fld.str);
		fld.str = NULL;
	}
	return (str);
}

char			*signal_space(char *str, t_fields fld)
{
	if (*str != '-')
	{
		fld.str = str;
		if (((fld.flag / 100) % 10))
			str = ft_strdup("+");
		else if (((fld.flag / 10) % 10))
			str = ft_strdup(" ");
		else
			str = ft_strdup("");
		str = ft_concat(str, fld.str);
		free(fld.str);
		fld.str = NULL;
	}
	return (str);
}

char			*format_txt(t_printf ptf, va_list ap)
{
	t_fields	fld;

	fld = set_fields(ptf.begin, ptf.end, fld);
	if (fld.rtrn == -1)
		return (NULL);
	if (fld.pnt_w)
		fld.width = va_arg(ap, int);
	if (fld.pnt_p)
		fld.prec = va_arg(ap, int);
	if (*ptf.end == 'c' || *ptf.end == 's')
		return (c_or_s(ptf, fld, ap));
	if (*ptf.end == 'p' || *ptf.end == 'd' || *ptf.end == 'i')
		return (p_or_d_or_i(ptf, fld, ap));
	if (*ptf.end == 'u' || *ptf.end == '%')
		return (u_or_p100(ptf, fld, ap));
	if (*ptf.end == 'x' || *ptf.end == 'X')
		return (x_decimal(ptf, fld, ap));
	if (*ptf.end == 'n' || *ptf.end == 'f')
		return (n_or_f(ptf, fld, ap));
	if (*ptf.end == 'g')
		return (g_convesion(ptf, fld, ap));
	if (*ptf.end == 'e')
		return (e_scntfc(ptf, fld, ap));
	return (NULL);
}