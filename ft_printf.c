/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 13:31:44 by tmendes-          #+#    #+#             */
/*   Updated: 2020/07/17 13:24:23 by tmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

/*
** This function concatenates two pointers *dst and *src and
** maintaining the result in the pointer *dst.
*/

static t_llint	pot_b( int base,  int exp)
{
	t_llint	pot;

	if (exp <= 0)
		pot = 1;
	else
		pot = base * pot_b(base, exp - 1);
	return (pot);
}


int	nbr_exp(long double nbr)
{
	int			nbr_i;
	int			k;

	if (1/nbr < 0)
		nbr = -nbr;
	if(nbr == 0)
		return (0);
	else if (nbr >= 1)
		return ( (nbr_digit(nbr) - 1));
	else
	{
		k = 0;
		nbr_i = (int)nbr;
		while (nbr_i == 0)
		{
			k--;
			nbr_i = (int)(10*nbr);
			nbr = (10*nbr) - (long double)nbr_i;
		}
		return (k);
	}
}

static char *unpad(char *nbr, char chr)
{
	int		k;
	char	*exp;

	exp = ft_strchr(nbr, 'e');
	k = ft_strlen(nbr) - 1;
	if (chr == 'e')
	{
		k -= ft_strlen(exp);
		while ((*(nbr + k) == '0' || *(nbr + k) == '.') &&
		k > 0 && *(nbr + (k - 1)) != '-')
			k--;
		ft_memmove((nbr + k + 1), exp, ft_strlen(exp) + 1);
	}
	else
	{
		while (*(nbr + k) == '0' && k > 0 && *(nbr + (k - 1)) != '-')
			k--;
		if ( *(nbr + k) == '.')
			*(nbr + k) = 0;
		*(nbr + k + 1) = 0;
	}
	return (nbr);
}

static char	*p_exp(char *nbr, int prec)
{
	char	*exp;
	int		k;
	char	chr;

	printf ("\nNBR1: %s  prec = %d", nbr, prec);
	k = 1;
	while ( *(nbr + k) != '.')
		k++;
	ft_memmove((nbr + k), (nbr + k + 1), prec + 2);
	chr = *(nbr + prec + 2);
	printf("\nchar: %c", *(nbr + prec + 2));
	*(nbr + prec + 2) = 0;
	printf ("\nNBR2: %s  ", nbr);
	if ( chr >= '5')
		nbr = round_str(nbr);
	printf ("\nNBR3: %s  ", nbr);
	if (*nbr == '0')
	{
		nbr = ft_memmove(nbr, (nbr + 1), prec + 2);
		k--;
	}
	else
		*(nbr + prec + 1) = 0;
	printf ("\nNBR4: %s  ", nbr);
	ft_memmove((nbr + 2), (nbr + 1), prec + 1);
	*(nbr + 1) = '.';
	nbr = join_ptr(nbr,"e+");
	k--;
	if (k < 10)
		nbr = join_ptr(nbr,"0");
	exp = ft_llitoa(k, 10, 'a');
	nbr = join_ptr(nbr, exp);
	printf ("\n\nNBR5: %s  \n\n", nbr);
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
	char *aux;

	if (*nbr == '0')
	{
		nbr = n_exp(nbr, prec);
		return (nbr);
	}
	else
	{	aux = ft_strdup("0");
		aux = join_ptr(aux, nbr);
		aux = p_exp(aux, prec);
		free (nbr);
		nbr = NULL;
		return (aux);
	}
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
	fld.pstn = (fld.str + fld.k);
	return (fld);
}

static t_fields	w_or_p( t_fields fld, char chr)
{
	char	*nbrs;

	nbrs = "1234567890";
	fld.aux = 0;
	fld.j = 0;
	fld.k = 0;
	while (*(nbrs + fld.j) != 0)
	{
		if ( *(fld.pstn + fld.k) == *(nbrs + fld.j))
		{
			fld.aux = 10*fld.aux + *(nbrs + fld.j) - '0';
			fld.k++;
			fld.j = 0;
		}
		else
			fld.j++;
	}
	fld.pstn = (fld.pstn + fld.k);
	if (chr == 'w')
		fld.width = fld.aux;
	else if (chr == 'p')
		fld.prec = fld.aux;
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
	fld.pstn = NULL;
	fld.j = 0;
	fld.k = 0;
	fld.aux = 0;
	return (fld);
}

static char *format_txt(char *begin, char *end, va_list ap, char *final)
{
	char		*txt;
	char		conv;
	char		*hex;
	char		*aux;
	long double	flt;
	int			exp;
	t_fields	fields;

	fields = init_fields(fields);
	conv = *end;
	*end = 0;
	fields.str = ft_strdup(begin);
	hex = ft_strdup("0x");
	
	fields = flag(fields);
	if ( *(fields.pstn) == '*')
	{
		fields.pnt_w = 1;
		fields.pstn++;
	}
	else
		fields = w_or_p(fields, 'w');
	if ( *(fields.pstn) == '.' && *(fields.pstn + 1) == '*')
	{
		fields.pnt_p = 1;
		fields.pstn += 2;
	}
	else if ( *(fields.pstn) == '.')
	{
		fields.pstn++;
		fields = w_or_p(fields, 'p');
	}


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
		if (ft_strlen(fields.str) == 0)
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
		txt = ft_ftoa( flt, fields.prec);
		return (txt);
	}
	if (conv == 'g')
	{
		flt = (long double)va_arg(ap, double);
		exp = nbr_exp(flt);
		if (exp < -4 || exp >= fields.prec)
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
			aux = ft_ftoa(flt, exp + fields.prec + 1);
			aux = scntfc_not(aux, fields.prec - 1);
			aux = unpad(aux, 'e');
			txt = join_ptr(txt,aux);
		}
		else
			txt = ft_ftoa( flt, fields.prec - (exp + 1));		
		txt = unpad(txt, 'f');
		return (txt);
	}
	if (conv == 'e')
	{
		flt = (long double)va_arg(ap, double);
		exp = nbr_exp(flt);
		if ((1 / flt) < 0)
		{
			flt = -flt;
			txt = ft_strdup("-");
		}
		else
			txt = ft_strdup("");
		if (exp < 0)
			exp = -exp;
		aux = ft_ftoa(flt, exp + fields.prec + 1);
		printf ("\n\nAux: %s\n", aux);
		aux = scntfc_not(aux, fields.prec);
		printf ("Aux: %s\n", aux);
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