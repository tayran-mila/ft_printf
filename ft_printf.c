/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 13:31:44 by tmendes-          #+#    #+#             */
/*   Updated: 2020/07/10 11:50:42 by tmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** This function concatenates two pointers *dst and *src and
** maintaining the result in the pointer *dst.
*/

static char	*conversion(char *begin)
{
	int		i;
	char	*conv;

	i = 0;
	while (*(begin + i))
	{
		conv = ft_strchr("cspdiuxX%nfge", *(begin + i));
		if (conv)
			return (begin + i);
		i++;
	}
	return (NULL);
}

static char *format_txt(char *begin, char *end, va_list ap, char *final)
{
	char	*txt;
	char	*flg;
	char	conv;
	char	*hex;

	conv = *end;
	*end = 0;
	flg = ft_strdup(begin);
	ft_putstr_fd("@", 1);
	ft_putstr_fd(flg, 1);
	ft_putstr_fd("@", 1);
	hex = ft_strdup("0x");
	if (conv == 'c')
	{
		txt = ft_strdup("");
		*txt = (char) va_arg(ap, int);
		return (txt);
	}
	if (conv == 's')
	{
		txt = va_arg(ap, char *);
		return (txt);
	}
	if (conv == 'p')
	{
		txt = ft_strdup("0x");
		hex = ft_llitoa((unsigned long int) va_arg (ap, void *), 16, 'a');
		txt = join_ptr(txt,hex);
		free (hex);
		hex = NULL;
		return (txt);
	}
	if (conv == 'd' || conv == 'i')
	{
		txt = ft_llitoa(va_arg(ap, int), 10, 'a');
		return (txt);
	}
	if (conv == 'u')
	{
		txt = ft_llitoa(va_arg(ap, unsigned int), 10, 'a');
		return (txt);
	}
	if (conv == 'x')
	{
		txt = ft_llitoa(va_arg(ap, long long int), 16, 'a');
		return (txt);
	}
	if (conv == 'X')
	{
		txt = ft_llitoa(va_arg(ap, long long int), 16, 'A');
		return (txt);
	}
	if (conv == '%')
	{
		if (ft_strlen(flg) == 0)
		{
			txt = ft_strdup("%");
			return (txt);
		}
		return (NULL);
	}


	if (conv == 'n')
	{
		*va_arg(ap, int *) = (int) ft_strlen(final);
		txt = ft_strdup("");
		return (txt);
	}
	if (conv == 'f')
	{
		txt = ft_ftoa((long double)va_arg(ap, double), 3);
		return (txt);
	}
	if (conv == 'g')
	{
		txt = ft_ftoa((long double)va_arg(ap, double), 3);
		return (txt);
	}
	if (conv == 'e')
	{
		txt = ft_ftoa((long double)va_arg(ap, double), 3);
		return (txt);
	}
	return (NULL);
}

int			ft_printf(const char *format, ...)
{
	char		*ptr;
	char		*begin;
	char		*end;
	char		*final;
	char		*txt;
	va_list 	ap;

	va_start(ap, format);
	ptr = ft_strdup(format);
	final = ft_strdup("");
	while (ft_strlen(ptr))
	{
		if ((begin = ft_strchr(ptr, '%')))
		{
			*begin = 0;
			final = join_ptr(final, ptr);
			if (!(end = conversion(begin + 1)) ||
			!(txt = format_txt(begin + 1, end, ap, final)) ||
			!(final = join_ptr(final, txt)) ||
			!(ptr = ft_memmove(ptr, (end + 1), ft_strlen(end + 1) + 1)))
				return (-1);
		}
		else
		{
			final = join_ptr(final, ptr);
			*ptr = 0;
		}
	}
	ft_putstr_fd(final, 1);
	va_end(ap);
	return (ft_strlen(final));
}