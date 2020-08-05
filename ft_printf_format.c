/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 08:20:06 by tmendes-          #+#    #+#             */
/*   Updated: 2020/08/05 13:12:39 by tmendes-         ###   ########.fr       */
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

static char		*pad_aux(char *str, t_fields fld, char chr)
{
	if ((*fld.str == '-' || *fld.str == '+' ||
	*fld.str == ' ') && chr == 'p')
		fld.itg++;
	if (!(str = repeat_chr('0', fld.itg)))
		return (NULL);
	if ((*fld.str == '-' || *fld.str == ' ' ||
	*fld.str == '+') && fld.itg != 0)
	{
		*str = *fld.str;
		*fld.str = '0';
	}
	return (str);
}

char			*pad_str(char *str, t_fields fld, int len, char chr)
{
	fld.itg = len - ft_strlen(str);
	if (fld.itg >= 0)
	{
		if (fld.flag[4] && chr != 'p')
			fld.str = repeat_chr(' ', fld.itg);
		else
		{
			fld.str = str;
			if (fld.flag[3])
				str = pad_aux(str, fld, chr);
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

t_printf		format_txt(t_printf ptf, va_list ap)
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
