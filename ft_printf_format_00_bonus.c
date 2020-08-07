/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_00_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 08:20:06 by tmendes-          #+#    #+#             */
/*   Updated: 2020/08/07 08:16:09 by tmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

char				*signal_space(char *str, t_fields fld)
{
	if (*str != '-')
	{
		fld.str = str;
		if (fld.flag[2])
			str = ft_strdup("+");
		else if (fld.flag[1])
			str = ft_strdup(" ");
		else
			str = ft_strdup("");
		str = ft_concat(str, fld.str);
		free(fld.str);
		fld.str = NULL;
	}
	return (str);
}

static t_printf		bonus(t_printf ptf, t_fields fld, va_list ap)
{
	if (*ptf.end == 'n')
		return (n____type(ptf, fld, ap));
	if (*ptf.end == 'f')
		return (f____type(ptf, fld, ap));
	if (*ptf.end == 'g')
		return (g____type(ptf, fld, ap));
	if (*ptf.end == 'e')
		return (e____type(ptf, fld, ap));
	if (*ptf.end == 'o')
		return (o____type(ptf, fld, ap));
	ptf.rtrn = -1;
	return (ptf);
}

t_printf			format_txt(t_printf ptf, va_list ap)
{
	t_fields fld;

	fld = init_fields();
	fld = set_fields(ptf.begin, ptf.end, fld);
	ptf.rtrn = fld.rtrn;
	if (fld.pnt_w)
		fld.width = va_arg(ap, int);
	if (fld.pnt_p)
		fld.prec = va_arg(ap, int);
	if (*ptf.end == 'c')
		return (c____type(ptf, fld, ap));
	if (*ptf.end == 's')
		return (s____type(ptf, fld, ap));
	if (*ptf.end == 'p')
		return (p____type(ptf, fld, ap));
	if (*ptf.end == 'd' || *ptf.end == 'i')
		return (d____type(ptf, fld, ap));
	if (*ptf.end == 'u')
		return (u____type(ptf, fld, ap));
	if (*ptf.end == '%')
		return (p100_type(ptf, fld));
	if (*ptf.end == 'x' || *ptf.end == 'X')
		return (x____type(ptf, fld, ap));
	return (bonus(ptf, fld, ap));
}
