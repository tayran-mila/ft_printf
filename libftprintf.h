/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 13:31:08 by tmendes-          #+#    #+#             */
/*   Updated: 2020/08/06 08:35:38 by tmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <wchar.h>
# include "libft/libft.h"

typedef struct	s_fields
{
	int			flag[5];
	int			pnt_w;
	int			width;
	int			pnt_p;
	int			prec;
	int			prec_s;
	int			len_h;
	int			len_l;
	int			rtrn;
	void		*ptr;
	char		*str;
	long double	flt;
	t_llint		llint;
	t_ullint	ullint;
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
	long int	*pstn;
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

char			*signal_space(char *str, t_fields fld);
t_printf		format_txt(t_printf ptf, va_list ap);

char			*pad_str(char *str, t_fields fld, int len, char chr);

t_fields		set_fields(char *begin, char *end, t_fields fields);

t_printf		c____type(t_printf ptf, t_fields fld, va_list ap);
t_printf		s____type(t_printf ptf, t_fields fld, va_list ap);
t_printf		p____type(t_printf ptf, t_fields fld, va_list ap);
t_printf		p100_type(t_printf ptf, t_fields fld);

t_printf		d____type(t_printf ptf, t_fields fld, va_list ap);
t_printf		u____type(t_printf ptf, t_fields fld, va_list ap);
t_printf		x____type(t_printf ptf, t_fields fld, va_list ap);

t_printf		g____type(t_printf ptf, t_fields fld, va_list ap);
t_printf		e____type(t_printf ptf, t_fields fld, va_list ap);

char			*unpad(char *nbr, char chr);
t_printf		n____type(t_printf ptf, t_fields fld, va_list ap);
t_printf		f____type(t_printf ptf, t_fields fld, va_list ap);

int				nbr_exp(long double nbr, int prec);
char			*scntfc_not(char *nbr, int prec);

t_printf		init_printf(void);
t_printf		end_printf(t_printf ptf);
t_fields		init_fields(void);
t_scntfc		init_scntfc(void);

#endif
