/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 13:31:44 by tmendes-          #+#    #+#             */
/*   Updated: 2020/07/25 08:55:33 by tmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char			*str_srch(char *begin, char *set)
{
	int		i;
	char	*conv;

	i = 0;
	while (*(begin + i))
	{
		conv = ft_strchr(set, *(begin + i));
		if (conv)
			return (begin + i);
		i++;
	}
	return (NULL);
}

static t_printf		init_printf(void)
{
	t_printf ptf;

	ptf.rtrn = 0;
	ptf.len = 0;
	ptf.ptr = NULL;
	ptf.begin = NULL;
	ptf.end = NULL;
	ptf.final = NULL;
	ptf.txt = NULL;
	return (ptf);
}

static t_printf		end_printf(t_printf ptf)
{
	free(ptf.ptr);
	free(ptf.final);
	free(ptf.txt);
	ptf.ptr = NULL;
	ptf.begin = NULL;
	ptf.end = NULL;
	ptf.final = NULL;
	ptf.txt = NULL;
	return (ptf);
}

static t_printf		printf_str(const char *format, t_printf ptf, va_list ap)
{
	ptf.ptr = ft_strdup(format);
	ptf.final = ft_strdup("");
	while (ft_strlen(ptf.ptr))
	{
		if ((ptf.begin = ft_strchr(ptf.ptr, '%')))
		{
			*ptf.begin = 0;
			ptf.begin++;
			if (!(ptf.final = ft_concat(ptf.final, ptf.ptr)) ||
			!(ptf.end = str_srch(ptf.begin, "cspdiuxX%nfge")) ||
			!(ptf.txt = format_txt(ptf, ap)) ||
			!(ptf.final = ft_concat(ptf.final, ptf.txt)) ||
			!(ptf.ptr = ft_memmove(ptf.ptr, (ptf.end + 1),
			ft_strlen(ptf.end + 1) + 1)))
				ptf.rtrn = -1;
			free(ptf.txt);
			ptf.txt = NULL;
		}
		else
		{
			if (!(ptf.final = ft_concat(ptf.final, ptf.ptr)))
				ptf.rtrn = -1;
			*ptf.ptr = 0;
		}
	}
	ptf.len += ft_strlen(ptf.final);
	return (ptf);
}

int					ft_printf(const char *format, ...)
{
	t_printf	ptf;
	va_list		ap;

	va_start(ap, format);
	ptf = init_printf();
	ptf = printf_str(format, ptf, ap);
	va_end(ap);
	if (ptf.rtrn == -1)
		return (ptf.rtrn);
	else
	{
		ft_putstr_fd(ptf.final, 1);
		ptf = end_printf(ptf);
		return (ptf.len);
	}
}
