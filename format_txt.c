/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_txt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 08:20:06 by tmendes-          #+#    #+#             */
/*   Updated: 2020/07/19 16:44:05 by tmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*repeat_chr(char chr, int nbr)
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

char	*pad_str(char *str, t_fields fld)
{
	fld.itg = fld.width - ft_strlen(str);
	if (fld.itg > 0)
	{
		if (((fld.flag/10000)%10))
			fld.str = repeat_chr(' ', fld.itg);
		else
		{
			fld.str = str;
			if (((fld.flag/1000)%10))
			{
				str = repeat_chr('0', fld.itg);
				if (*fld.str == '-' || *fld.str == ' ' || *fld.str == '+')
				{
					*str = *fld.str;
					*fld.str = '0';
				}
			}
			else
				str = repeat_chr(' ', fld.itg);
		}
		str = join_ptr(str, fld.str);
		free(fld.str);
		fld.str = NULL;	
	}
	return (str);
}



char *format_txt(t_printf ptf, va_list ap)
{
	t_fields	fld;

	fld = set_fields(ptf.begin, ptf.end, fld);
	if (*ptf.end == 'c')
	{
		ptf.txt = ft_strdup("");
		*ptf.txt = (char) va_arg(ap, int);
		ptf.txt = pad_str(ptf.txt, fld);
		return (ptf.txt);
	}
	if (*ptf.end == 's')
	{
		ptf.txt = va_arg(ap, char *);
		ptf.txt = pad_str(ptf.txt, fld);
		return (ptf.txt);
	}
	if (*ptf.end == 'p')
	{
		ptf.txt = ft_strdup("0x");
		fld.str = ft_llitoa((unsigned long int) va_arg (ap, void *), 16, 'a');
		ptf.txt = join_ptr(ptf.txt, fld.str);
		free (fld.str);
		fld.str = NULL;
		ptf.txt = pad_str(ptf.txt, fld);
		return (ptf.txt);
	}
	if (*ptf.end == 'd' || *ptf.end == 'i')
	{
		ptf.txt = ft_llitoa(va_arg(ap, int), 10, 'a');
		ptf.txt = pad_str(ptf.txt, fld);
		return (ptf.txt);
	}
	if (*ptf.end == 'u')
	{
		ptf.txt = ft_llitoa(va_arg(ap, unsigned int), 10, 'a');
		ptf.txt = pad_str(ptf.txt, fld);
		return (ptf.txt);
	}
	if (*ptf.end == 'x')
	{
		ptf.txt = ft_strdup("");
		if ( (fld.flag%10) == 1)
			ptf.txt = join_ptr(ptf.txt, "0x");
		fld.str = ft_llitoa(va_arg(ap, long long int), 16, 'a');
		ptf.txt = join_ptr(ptf.txt, fld.str);
		free (fld.str);
		fld.str = NULL;
		ptf.txt = pad_str(ptf.txt, fld);
		return (ptf.txt);
	}
	if (*ptf.end == 'X')
	{
		ptf.txt = ft_strdup("");
		if ( (fld.flag%10) == 1)
			ptf.txt = join_ptr(ptf.txt, "0X");
		fld.str = ft_llitoa(va_arg(ap, long long int), 16, 'A');
		ptf.txt = join_ptr(ptf.txt, fld.str);
		free (fld.str);
		fld.str = NULL;
		ptf.txt = pad_str(ptf.txt, fld);
		return (ptf.txt);
	}
	if (*ptf.end == '%')
	{
		if (ptf.begin == ptf.end)
		{
			ptf.txt = ft_strdup("%");
			return (ptf.txt);
		}
		return (NULL);
	}


	if (*ptf.end == 'n')
	{
		*va_arg(ap, int *) = (int) ft_strlen(ptf.final);
		ptf.txt = ft_strdup("");
		return (ptf.txt);
	}
	if (*ptf.end == 'f')
	{
		fld.flt = (long double)va_arg(ap, double);
		ptf.txt = ft_ftoa( fld.flt, fld.prec);
		if ( fld.prec == 0 && fld.flag%10 == 0)
			ptf.txt = unpad(ptf.txt, 'f');
		ptf.txt = pad_str(ptf.txt, fld);
		return (ptf.txt);
	}
	if (*ptf.end == 'g')
	{
		if ( fld.prec == 0)
			fld.prec++;
		fld.flt = (long double)va_arg(ap, double);
		fld.itg = nbr_exp(fld.flt);
		if (fld.itg < -4 || fld.itg >= fld.prec)
		{
			if ((1 / fld.flt) < 0)
			{
				fld.flt = -fld.flt;
				ptf.txt = ft_strdup("-");
			}
			else
				ptf.txt = ft_strdup("");
			if (fld.itg < 0)
				fld.itg = -fld.itg;
			fld.str = ft_ftoa(fld.flt, fld.itg + fld.prec + 1);
			fld.str = scntfc_not(fld.str, fld.prec - 1);
			if ( fld.flag%10 == 0)
				fld.str = unpad(fld.str, 'e');
			ptf.txt = join_ptr(ptf.txt, fld.str);
			free(fld.str);
			fld.str = NULL;
		}
		else
			ptf.txt = ft_ftoa( fld.flt, fld.prec - (fld.itg + 1));
		if ( fld.flag%10 == 0)
			ptf.txt = unpad(ptf.txt, 'f');
		ptf.txt = pad_str(ptf.txt, fld);
		return (ptf.txt);
	}
	if (*ptf.end == 'e')
	{
		fld.flt = (long double)va_arg(ap, double);
		fld.itg = nbr_exp(fld.flt);
		if ((1 / fld.flt) < 0)
		{
			fld.flt = -fld.flt;
			ptf.txt = ft_strdup("-");
		}
		else
			ptf.txt = ft_strdup("");
		if (fld.itg < 0)
			fld.itg = -fld.itg;
		fld.str = ft_ftoa(fld.flt, fld.itg + fld.prec + 1);
		fld.str = scntfc_not(fld.str, fld.prec);
		ptf.txt = join_ptr(ptf.txt, fld.str);
		free(fld.str);
		fld.str = NULL;
		if ( fld.prec == 0 && fld.flag%10 == 0)
			ptf.txt = unpad(ptf.txt, 'e');
		ptf.txt = pad_str(ptf.txt, fld);
		return (ptf.txt);
	}
	return (NULL);
}