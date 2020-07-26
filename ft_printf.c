/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 13:31:44 by tmendes-          #+#    #+#             */
/*   Updated: 2020/07/26 12:15:16 by tmendes-         ###   ########.fr       */
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
	ptf.pstn = NULL;
	return (ptf);
}

static t_printf		end_printf(t_printf ptf)
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
			ptf.final = ft_concat(ptf.final, ptf.ptr);
			ptf.end = str_srch(ptf.begin, "cspdiuxX%nfge");
			ptf = format_txt(ptf, ap);
			ptf.final = ft_concat(ptf.final, ptf.txt);
			ptf.ptr = ft_memmove(ptf.ptr, (ptf.end + 1),
			ft_strlen(ptf.end + 1) + 1);
			free(ptf.txt);
			ptf.txt = NULL;
		}
		else
		{
			ptf.final = ft_concat(ptf.final, ptf.ptr);
			*ptf.ptr = 0;
		}
	}
	return (ptf);
}

int					ft_printf(const char *format, ...)
{
	t_printf	ptf;
	va_list		ap;
	int			k;

	va_start(ap, format);
	ptf = init_printf();
	ptf = printf_str(format, ptf, ap);
	va_end(ap);
	if (ptf.final != NULL)
	{
		ptf.len = ft_strlen(ptf.final);
		k = 0;
		if(ptf.pstn)
		{
			while (*(ptf.pstn + k) != -1)
			{
				ptf.final[*(ptf.pstn + k)] = 0;
				k++;
			}
		}
		write(1, ptf.final, ptf.len);
		ptf = end_printf(ptf);
		return (ptf.len);
	}
	else
	{
		ptf = end_printf(ptf);
		return (-1);
	}
		
}
