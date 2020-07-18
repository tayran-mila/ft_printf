/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 13:31:08 by tmendes-          #+#    #+#             */
/*   Updated: 2020/07/18 15:40:39 by tmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct	s_fields
{
	int			flag;
	int			pnt_w;
	int			width;
	int			pnt_p;
	int			prec;
	int			len_mod;
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

int			ft_printf(const char *format, ...);
char		*join_ptr(char *dst, char *src);
char 		*ft_ftoa(long double nbr, int dig);
char		*str_srch(char *begin, char *set);
char 		*round_str(char *final);
int			nbr_digit(long double nbr);
int			nbr_exp(long double nbr);
char 		*format_txt(t_printf ptf, va_list ap);
t_fields	set_fields(char *begin, char *end, t_fields fields);
char		*scntfc_not(char *nbr, int prec);
char		*unpad(char *nbr, char chr);

#endif
