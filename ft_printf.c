/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 13:31:44 by tmendes-          #+#    #+#             */
/*   Updated: 2020/07/15 12:57:38 by tmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** This function concatenates two pointers *dst and *src and
** maintaining the result in the pointer *dst.
*/

static char *unpad(char *nbr)
{
	int	k;

	k = ft_strlen(nbr) - 1;
	while ((*(nbr + k) == '0' || *(nbr + k) == '.') &&
	k > 0 && *(nbr + (k - 1)) != '-')
	{
		*(nbr + k) = 0;
		k--;
	}
	return (nbr);
}

static char	*p_exp(char *nbr, int prec)
{
	char	*exp;
	int		k;
	char	chr;

	k = 1;
	while ( *(nbr + k) != '.')
		k++;
	ft_memmove((nbr + k), (nbr + k + 1), prec + 1);
	chr = *(nbr + prec + 1);
	*(nbr + prec + 1) = 0;
	if ( chr >= '5')
		nbr = round_str(nbr);
	ft_memmove((nbr + 2), (nbr + 1), prec + 1);
	*(nbr + 1) = '.';
	nbr = join_ptr(nbr,"e+");
	k--;
	if (k < 10)
		nbr = join_ptr(nbr,"0");
	exp = ft_llitoa(k, 10, 'a');
	nbr = join_ptr(nbr, exp);
	free(exp);
	exp = NULL;
	return (nbr);
}

static char	*n_exp(char *nbr, int prec)
{
	char	*point;
	char	*exp;
	int		k;
	char	chr;

	point = ft_strchr(nbr, '.');
	k = 1;
	while ( *(point + k) == '0')
		k++;
	if ( *(point + k) == 0)
	{
		*(nbr + prec + 2) = 0;
		nbr = join_ptr(nbr,"e+00");
		return (nbr);
	}
	nbr = ft_memmove(nbr, (point + k), prec + 2);
	chr = *(nbr + prec + 1);
	*(nbr + prec + 1) = 0;
	if ( chr >= '5')
		nbr = round_str(nbr);
	ft_memmove((nbr + 2), (nbr + 1), prec + 1);
	*(nbr + 1) = '.';
	nbr = join_ptr(nbr,"e-");
	if (k < 10)
		nbr = join_ptr(nbr,"0");
	exp = ft_llitoa(k, 10, 'a');
	nbr = join_ptr(nbr, exp);
	free(exp);
	exp = NULL;
	return (nbr);
}

static char	*scntfc_not(char *nbr, int prec)
{
	if (*nbr == '0')
		nbr = n_exp(nbr, prec);
	else
		nbr = p_exp(nbr, prec);
	return (nbr);
}

char	*str_srch(char *begin, char *set)
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

static char *format_txt(char *begin, char *end, va_list ap, char *final)
{
	char		*txt;
	char		*flg;
	char		conv;
	char		*hex;
	char		*aux;
	long double	flt;
	int			prec;
	int			exp;

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
		flt = (long double)va_arg(ap, double);
		txt = ft_ftoa( flt, 6);
		return (txt);
	}
	if (conv == 'g')
	{
		prec = 6;
		flt = (long double)va_arg(ap, double);
		exp = nbr_exp(flt);
		if (exp < -4 || exp >= prec)
		{
			if ((1 / flt) < 0)
			{
				flt = -flt;
				txt = ft_strdup("-");
			}
			else
				txt = ft_strdup("");
			if (exp < 0)
				exp = -exp;
			aux = ft_ftoa(flt, exp + prec + 1);
			aux = scntfc_not(aux, prec -1);
			txt = join_ptr(txt,aux);
		}
		else
		{
			//if (exp < 0)
				//exp = -exp;
			txt = ft_ftoa( flt, prec - (exp + 1));		
		}
		txt = unpad(txt);
		return (txt);
	}
	if (conv == 'e')
	{
		flt = (long double)va_arg(ap, double);
		if ((1 / flt) < 0)
		{
			flt = -flt;
			txt = ft_strdup("-");
		}
		else
			txt = ft_strdup("");
		aux = ft_ftoa( flt, 150);
		aux = scntfc_not(aux, 6);
		txt = join_ptr(txt,aux);
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
			if (!(end = str_srch(begin + 1, "cspdiuxX%nfge")) ||
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