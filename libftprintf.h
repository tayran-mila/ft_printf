/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 13:31:08 by tmendes-          #+#    #+#             */
/*   Updated: 2020/07/22 12:32:39 by tmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <wchar.h>
# include "libft/libft.h"

# include <stdio.h>

typedef struct	s_fields
{
	int			flag;
	int			pnt_w;
	int			width;
	int			pnt_p;
	int			prec;
	int			len_h;
	int			len_l;
	int			rtrn;
	char		*str;
	long double	flt;
	int			itg;
	int			j;
	int			k;
}				t_fields;

typedef struct	s_printf
{
	char		*ptr;
	char		*begin;
	char		*end;
	char		*final;
	char		*txt;
	int			rtrn;
	int			len;
}				t_printf;

typedef struct	s_scntfc
{
	char		*exp;
	char		*ptr;
	char		chr;
	int			itg;
}				t_scntfc;

int				ft_printf(const char *format, ...);
int				nbr_exp(long double nbr);
char			*format_txt(t_printf ptf, va_list ap);
t_fields		init_fields(void);
t_fields		set_fields(char *begin, char *end, t_fields fields);
char			*scntfc_not(char *nbr, int prec);

typedef	long long int	t_llint;

char			*c_or_s(t_printf ptf, t_fields fld, va_list ap);
char			*p_or_d_or_i(t_printf ptf, t_fields fld, va_list ap);
char			*u_or_p100(t_printf ptf, t_fields fld, va_list ap);
char			*x_decimal(t_printf ptf, t_fields fld, va_list ap);

char			*e_scntfc(t_printf ptf, t_fields fld, va_list ap);
char			*n_or_f(t_printf ptf, t_fields fld, va_list ap);
char			*g_convesion(t_printf ptf, t_fields fld, va_list ap);

char			*pad_str(char *str, t_fields fld);
char			*signal_space(char *str, t_fields fld);

#endif
