/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fields_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 08:32:59 by tmendes-          #+#    #+#             */
/*   Updated: 2020/08/07 08:16:01 by tmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

static t_fields		flag(t_fields fld)
{
	char	*flags;

	flags = "# +0-";
	fld.j = -1;
	while (++fld.j < (int)ft_strlen(flags))
		fld.flag[fld.j] = 0;
	fld.j = 0;
	fld.k = 0;
	while (*(flags + fld.j) != 0)
	{
		if (*(fld.str + fld.k) == *(flags + fld.j))
		{
			fld.flag[fld.j] += 1;
			fld.k++;
			fld.j = 0;
		}
		else
			fld.j++;
	}
	fld.str += fld.k;
	return (fld);
}

static t_fields		init_w_or_p(t_fields fld)
{
	if (*fld.str == '-')
	{
		fld.prec_s = -1;
		fld.str++;
	}
	fld.itg = 0;
	fld.j = 0;
	fld.k = 0;
	return (fld);
}

static t_fields		w_or_p(t_fields fld, char chr)
{
	char	*nbrs;

	nbrs = "1234567890";
	fld = init_w_or_p(fld);
	while (*(nbrs + fld.j) != 0)
	{
		if (*(fld.str + fld.k) == *(nbrs + fld.j))
		{
			fld.itg = 10 * fld.itg + *(nbrs + fld.j) - '0';
			fld.k++;
			fld.j = 0;
		}
		else
			fld.j++;
	}
	fld.str += fld.k;
	if (chr == 'w')
		fld.width = fld.itg;
	else if (chr == 'p')
		fld.prec = fld.itg;
	return (fld);
}

static t_fields		h_or_l(t_fields fld, char *end)
{
	fld.itg = 0;
	while (fld.str < end)
	{
		if (*fld.str == 'h')
			fld.len_h++;
		else if (*fld.str == 'l')
			fld.len_l++;
		else
			fld.rtrn = -1;
		fld.str++;
		fld.itg++;
	}
	if ((fld.len_h * fld.len_l) != 0 || fld.itg > 2)
		fld.rtrn = -1;
	return (fld);
}

t_fields			set_fields(char *begin, char *end, t_fields fields)
{
	fields.str = begin;
	fields = flag(fields);
	if (*(fields.str) == '*')
	{
		fields.pnt_w = 1;
		fields.str++;
	}
	else
		fields = w_or_p(fields, 'w');
	if (*(fields.str) == '.' && *(fields.str + 1) == '*')
	{
		fields.pnt_p = 1;
		fields.str += 2;
		fields.prec_s++;
	}
	else if (*(fields.str) == '.')
	{
		fields.str++;
		fields.prec_s++;
		fields = w_or_p(fields, 'p');
	}
	fields = h_or_l(fields, end);
	return (fields);
}
