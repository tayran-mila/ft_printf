/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_01.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 08:20:06 by tmendes-          #+#    #+#             */
/*   Updated: 2020/08/06 08:17:11 by tmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char			*repeat_chr(char chr, int nbr)
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

static char			*pad_aux(char *str, t_fields fld, char chr)
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

char				*pad_str(char *str, t_fields fld, int len, char chr)
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
