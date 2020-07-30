/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 13:12:18 by tmendes-          #+#    #+#             */
/*   Updated: 2020/07/30 07:33:29 by tmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

int main()
{
	int		a = -4;
	int		b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";

	int ptf1;
	int ptf2;


	while (a < 5) //T34-69
	{
		printf("\n");
		//printf("%*i, %*d, %*d, %*d, %*d, %*d, %*d, %*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
		//printf("%0*i, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
		//printf("%-*i, %-*d, %-*d, %-*d, %-*d, %-*d, %-*d, %-*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
		printf("%.*i, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
		printf("\n");

		printf("\n");
		//ft_printf("%*i, %*d, %*d, %*d, %*d, %*d, %*d, %*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
		//ft_printf("%0*i, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
		//ft_printf("%-*i, %-*d, %-*d, %-*d, %-*d, %-*d, %-*d, %-*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
		ft_printf("%.*i, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
		printf("\n");
		printf("\n");
		a++;
	}








	//printf("\n");
	//ptf1 = printf("%.1g", -9.999);
	//ptf1 = printf("%ld %hhd %hd", l_neg_1, ch_pos_1, sh_pos_1);
	//ptf1 = printf("%lli %d %ld", ll_neg_1, i_pos_1, l_pos_1);
	//ptf1 = printf("%li %hhi %hi", l_neg_1, ch_pos_1, sh_pos_1);
	//ptf1 = printf("%lli %i %li", ll_neg_1, i_pos_1, l_pos_1);
	//printf(" %d", ptf1);
	//printf("\n");

	//printf("\n");
	//ptf2 = ft_printf("%.1g", -9.999);
	//ptf2 = ft_printf("%ld %hhd %hd", l_neg_1, ch_pos_1, sh_pos_1);
	//ptf2 = ft_printf("%lli %d %ld", ll_neg_1, i_pos_1, l_pos_1);
	//ptf2 = ft_printf("%li %hhi %hi", l_neg_1, ch_pos_1, sh_pos_1);
	//ptf2 = ft_printf("%lli %i %li", ll_neg_1, i_pos_1, l_pos_1);
	//printf(" %d", ptf2);
	//printf("\n");

	return(0);
}
