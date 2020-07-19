/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fields.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 08:32:59 by tmendes-          #+#    #+#             */
/*   Updated: 2020/07/19 15:15:31 by tmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static t_llint	pot_b( int base,  int exp)
{
	t_llint	pot;

	if (exp <= 0)
		pot = 1;
	else
		pot = base * pot_b(base, exp - 1);
	return (pot);
}

static t_fields	flag( t_fields fld)
{
	char	*flags;

	flags = "# +0-";
	fld.flag = 0;
	fld.j = 0;
	fld.k = 0;
	while (*(flags + fld.j) != 0)
	{
		if ( *(fld.str + fld.k) == *(flags + fld.j))
		{
			if ((fld.flag/pot_b(10, fld.j)%10) == 0)
				fld.flag += pot_b(10, fld.j);
			fld.k++;
			fld.j = 0;
		}
		else
			fld.j++;
	}
	fld.str += fld.k;
	return (fld);
}

static t_fields	w_or_p( t_fields fld, char chr)
{
	char	*nbrs;

	nbrs = "1234567890";
	fld.itg = 0;
	fld.j = 0;
	fld.k = 0;
	while (*(nbrs + fld.j) != 0)
	{
		if ( *(fld.str + fld.k) == *(nbrs + fld.j))
		{
			fld.itg = 10*fld.itg + *(nbrs + fld.j) - '0';
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

static t_fields init_fields( t_fields fld)
{
	fld.flag = 0;
	fld.pnt_w = 0;
	fld.width = 0;
	fld.pnt_p = 0;
	fld.prec = 6;
	fld.len_mod = 0;
	fld.str = NULL;
	fld.j = 0;
	fld.k = 0;
	fld.itg = 0;
	return (fld);
}

t_fields set_fields(char *begin, char *end, t_fields fields)
{
	fields = init_fields(fields);
	fields.str = begin;
	fields = flag(fields);
	if ( *(fields.str) == '*')
	{
		fields.pnt_w = 1;
		fields.str++;
	}
	else
		fields = w_or_p(fields, 'w');
	if ( *(fields.str) == '.' && *(fields.str + 1) == '*')
	{
		fields.pnt_p = 1;
		fields.str += 2;
	}
	else if ( *(fields.str) == '.')
	{
		fields.str++;
		fields = w_or_p(fields, 'p');
	}
	if (fields.str >= end)
		fields.rtrn = -1;
	return (fields);
}