/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_txt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 08:20:06 by tmendes-          #+#    #+#             */
/*   Updated: 2020/07/20 14:48:07 by tmendes-         ###   ########.fr       */
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
		//free(fld.str);
		fld.str = NULL;	
	}
	return (str);
}

char	*signal_space(char *str, t_fields fld)
{
	if ( *str != '-')
	{
		fld.str = str;
		if ((fld.flag/100)%10)
			str = ft_strdup("+");
		else if (((fld.flag/10)%10))
			str = ft_strdup(" ");
		else
			str = ft_strdup("");
		str = join_ptr(str, fld.str);
		free(fld.str);
		fld.str = NULL;
	}
	return (str);
}

char	*c_or_s(t_printf ptf, t_fields fld, va_list ap)
{
	if (*ptf.end == 'c')
	{
		ptf.txt = ft_strdup("");
		if (fld.len_l == 1)
			*ptf.txt = (char) va_arg(ap, wint_t);		
		else
			*ptf.txt = (char) va_arg(ap, int);
		ptf.txt = pad_str(ptf.txt, fld);
	}
	if (*ptf.end == 's')
	{
		if (fld.len_l == 1)
			ptf.txt = ft_strdup((char *)va_arg(ap, wchar_t *));			
		else
			ptf.txt = ft_strdup(va_arg(ap, char *));
		if (fld.prec < (int)ft_strlen(ptf.txt))
			*(ptf.txt + fld.prec) = 0;
		ptf.txt = pad_str(ptf.txt, fld);
	}
	return (ptf.txt);
}

char	*p_or_d_or_i(t_printf ptf, t_fields fld, va_list ap)
{
	if (*ptf.end == 'p')
	{
		ptf.txt = ft_strdup("0x");
		fld.str = ft_llitoa((unsigned long int) va_arg (ap, void *), 16, 'a');
		ptf.txt = join_ptr(ptf.txt, fld.str);
		free (fld.str);
		fld.str = NULL;
		ptf.txt = pad_str(ptf.txt, fld);
	}
	if (*ptf.end == 'd' || *ptf.end == 'i')
	{
		if (fld.len_h == 2)
			ptf.txt = ft_llitoa((signed char)va_arg(ap, int), 10, 'a');
		if (fld.len_h == 1)
			ptf.txt = ft_llitoa((short int)va_arg(ap, int), 10, 'a');
		if (fld.len_l == 2)
			ptf.txt = ft_llitoa(va_arg(ap, long int), 10, 'a');
		if (fld.len_l == 1)
			ptf.txt = ft_llitoa(va_arg(ap, long long int), 10, 'a');
		else
			ptf.txt = ft_llitoa(va_arg(ap, int), 10, 'a');
		ptf.txt = signal_space(ptf.txt, fld);
		ptf.txt = pad_str(ptf.txt, fld);
	}
	return (ptf.txt);
}

char	*u_or_p100(t_printf ptf, t_fields fld, va_list ap)
{
	if (*ptf.end == 'u')
	{
		if (fld.len_h == 2)
			ptf.txt = ft_llitoa((unsigned char)va_arg(ap, int), 10, 'a');
		if (fld.len_h == 1)
			ptf.txt = ft_llitoa((unsigned short int)va_arg(ap, int), 10, 'a');
		if (fld.len_l == 2)
			ptf.txt = ft_llitoa(va_arg(ap, unsigned long int), 10, 'a');
		if (fld.len_l == 1)
			ptf.txt = ft_llitoa(va_arg(ap, unsigned long long int), 10, 'a');
		else
			ptf.txt = ft_llitoa(va_arg(ap, unsigned int), 10, 'a');
		ptf.txt = pad_str(ptf.txt, fld);	
	}
	if (*ptf.end == '%')
	{
		if (ptf.begin == ptf.end)
			ptf.txt = ft_strdup("%");
		else
			return (NULL);
	}
	return (ptf.txt);
}

char	*x_decimal(t_printf ptf, t_fields fld, va_list ap)
{
	if ( (fld.flag%10) == 1)
	{
		ptf.txt = ft_strdup("0 ");
		*(ptf.txt + 1) = *ptf.end;
	}
	else
		ptf.txt = ft_strdup("");
	if (fld.len_h == 2)
		fld.str = ft_llitoa((unsigned char)va_arg(ap, int), 16, *ptf.end);
	if (fld.len_h == 1)
		fld.str = ft_llitoa((unsigned short int)va_arg(ap, int), 16, *ptf.end);
	if (fld.len_l == 2)
		fld.str = ft_llitoa(va_arg(ap, unsigned long int), 16, *ptf.end);
	if (fld.len_l == 1)
		fld.str = ft_llitoa(va_arg(ap, unsigned long long int), 16, *ptf.end);
	else
		fld.str = ft_llitoa(va_arg(ap, long long int), 16, *ptf.end);
	ptf.txt = join_ptr(ptf.txt, fld.str);
	free (fld.str);
	fld.str = NULL;
	ptf.txt = signal_space(ptf.txt, fld);
	ptf.txt = pad_str(ptf.txt, fld);
	return (ptf.txt);
}

char	*f_float(t_printf ptf, t_fields fld, va_list ap)
{
	if (*ptf.end == 'f' || *ptf.end == 'g')
	{
		fld.flt = (long double)va_arg(ap, double);
		ptf.txt = ft_ftoa( fld.flt, fld.prec);
		if ( fld.prec == 0 && fld.flag%10 == 0)
			ptf.txt = unpad(ptf.txt, 'f');
		ptf.txt = signal_space(ptf.txt, fld);
		ptf.txt = pad_str(ptf.txt, fld);
		return (ptf.txt);
	}
	else
		return (NULL);
}

char	*e_scntfc(t_printf ptf, t_fields fld, va_list ap)
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
	ptf.txt = signal_space(ptf.txt, fld);
	ptf.txt = pad_str(ptf.txt, fld);
	return (ptf.txt);
}

char	*n_or_g(t_printf ptf, t_fields fld, va_list ap)
{
	if (*ptf.end == 'n')
	{
		if (fld.len_h == 2)
			*va_arg(ap, signed char *) = (signed char)ft_strlen(ptf.final);
		if (fld.len_h == 1)
			*va_arg(ap, short int *) = (short int)ft_strlen(ptf.final);
		if (fld.len_l == 2)
			*va_arg(ap, long int *) = (long int)ft_strlen(ptf.final);
		if (fld.len_l == 1)
			*va_arg(ap, long long int *) = (long long int)ft_strlen(ptf.final);
		else
			*va_arg(ap, int *) = (int)ft_strlen(ptf.final);
		ptf.txt = ft_strdup("");
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
		ptf.txt = signal_space(ptf.txt, fld);
		ptf.txt = pad_str(ptf.txt, fld);
	}
	return (ptf.txt);
}

char	*format_txt(t_printf ptf, va_list ap)
{
	t_fields	fld;

	fld = set_fields(ptf.begin, ptf.end, fld);
	if (fld.rtrn == -1)
		return (NULL);
	if ( fld.pnt_w)
		fld.width = va_arg(ap, int);
	if ( fld.pnt_p)
		fld.prec = va_arg(ap, int);
	if (*ptf.end == 'c' || *ptf.end == 's')
		return (c_or_s(ptf, fld, ap));
	if (*ptf.end == 'p' || *ptf.end == 'd' || *ptf.end == 'i')
		return (p_or_d_or_i(ptf, fld, ap));	
	if (*ptf.end == 'u' || *ptf.end == '%')
		return (u_or_p100(ptf, fld, ap));
	if (*ptf.end == 'x' || *ptf.end == 'X')
		return (x_decimal(ptf, fld, ap));
	if (*ptf.end == 'f')
		return (f_float(ptf, fld, ap));
	if (*ptf.end == 'e')
		return (e_scntfc(ptf, fld, ap));
	if (*ptf.end == 'n' || *ptf.end == 'g')
		return (n_or_g(ptf, fld, ap));




	/*if (*ptf.end == 'g')
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
		ptf.txt = signal_space(ptf.txt, fld);
		ptf.txt = pad_str(ptf.txt, fld);
		return (ptf.txt);
	}*/
	
	return (NULL);
}