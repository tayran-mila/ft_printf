/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_structures_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 15:26:47 by tmendes-          #+#    #+#             */
/*   Updated: 2020/08/07 08:16:44 by tmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

t_printf		init_printf(void)
{
	t_printf ptf;

	ptf.rtrn = 0;
	ptf.len = 0;
	ptf.ptr = NULL;
	ptf.begin = NULL;
	ptf.end = NULL;
	ptf.final = NULL;
	ptf.txt = NULL;
	ptf.pstn = NULL;
	return (ptf);
}

t_printf		end_printf(t_printf ptf)
{
	free(ptf.ptr);
	free(ptf.final);
	free(ptf.txt);
	free(ptf.pstn);
	ptf.ptr = NULL;
	ptf.begin = NULL;
	ptf.end = NULL;
	ptf.final = NULL;
	ptf.txt = NULL;
	ptf.pstn = NULL;
	return (ptf);
}

t_fields		init_fields(void)
{
	t_fields	fld;
	int			k;

	k = -1;
	while (++k < 5)
		fld.flag[k] = 0;
	fld.pnt_w = 0;
	fld.width = 0;
	fld.pnt_p = 0;
	fld.prec = 6;
	fld.prec_s = 0;
	fld.len_h = 0;
	fld.len_l = 0;
	fld.ptr = NULL;
	fld.str = NULL;
	fld.flt = 0;
	fld.llint = 0;
	fld.ullint = 0;
	fld.j = 0;
	fld.k = 0;
	fld.itg = 0;
	return (fld);
}

t_scntfc		init_scntfc(void)
{
	t_scntfc sci;

	sci.exp = NULL;
	sci.ptr = NULL;
	sci.chr = 0;
	sci.itg = 0;
	return (sci);
}
