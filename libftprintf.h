/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 13:31:08 by tmendes-          #+#    #+#             */
/*   Updated: 2020/07/14 07:06:18 by tmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

int		ft_printf(const char *format, ...);
char	*join_ptr(char *dst, char *src);
char 	*ft_ftoa(long double nbr, int dig);
char	*str_srch(char *begin, char *set);
char 	*round_str(char *final);

#endif
