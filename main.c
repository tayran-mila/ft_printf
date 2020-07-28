/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 13:12:18 by tmendes-          #+#    #+#             */
/*   Updated: 2020/07/28 16:29:02 by tmendes-         ###   ########.fr       */
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
	int		ptf1;
	int		ptf2;
	char	*str;

	long long	lli;

	lli = 22337203685477;
	//lli = 2147;

	unsigned long long int ulli;

	ulli = 999999;
	str = ft_ullitoa(ulli, 10, 'z');
	printf("\nstr = %s digt = %d\n", str, ft_ull_nbrdigit(ulli, 10));
	free(str);
	str = NULL;
	printf("\n");

	
	printf("\n");
	ptf1 = printf("%lld", lli); //T2
	//ptf1 = printf("%.f %.f %.f %.f %.f %.f %.f %.f %.f %.f ", -0.05, -0.15, -2.5, -3.5, -4.5, -5.5, -6.5, -7.5, -8.5, -9.5); //T2
	//ptf1 = printf("%.f %.f %.f %.f %.f %.f %.f %.f %.f %.f", 0.05, 0.15, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5, 9.5);
	//ptf1 = printf("%.f %.f %.f %.f %.f %.f %.f %.f %.f %.f ", -0.501, -1.55, -2.55, -3.55, -4.55, -5.55, -6.55, -7.55, -8.55, -9.55); //T2
	//ptf1 = printf("%.f %.f %.f %.f %.f %.f %.f %.f %.f %.f", 0.501, 1.55, 2.55, 3.55, 4.55, 5.55, 6.55, 7.55, 8.55, 9.55);
	//ptf1 = printf("%c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %c %c %c %c %c %c %c %c %c %c %c %c %c", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0); //T2
	//ptf1 = printf("%c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %-*c, %-*c, %*c, %*c", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0); //T2
	printf(" %d", ptf1); //T2
	printf("\n");

	printf("\n");
	ptf2 = ft_printf("%lld", lli); //T2
	//ptf2 = ft_printf("%.f %.f %.f %.f %.f %.f %.f %.f %.f %.f ", -0.05, -0.15, -2.5, -3.5, -4.5, -5.5, -6.5, -7.5, -8.5, -9.5); //T2
	//ptf2 = ft_printf("%.f %.f %.f %.f %.f %.f %.f %.f %.f %.f", 0.05, 0.15, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5, 9.5);
	//ptf2 = ft_printf("%.f %.f %.f %.f %.f %.f %.f %.f %.f %.f ", -0.501, -1.55, -2.55, -3.55, -4.55, -5.55, -6.55, -7.55, -8.55, -9.55); //T2
	//ptf2 = ft_printf("%.f %.f %.f %.f %.f %.f %.f %.f %.f %.f", 0.501, 1.55, 2.55, 3.55, 4.55, 5.55, 6.55, 7.55, 8.55, 9.55);	//ptf2 = ft_printf("%c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %c %c %c %c %c %c %c %c %c %c %c %c %c", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0); //T2
	//ptf2 = ft_printf("%c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %-*c, %-*c, %*c, %*c", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0); //T2
	printf(" %d", ptf2); //T2
	printf("\n");

	return(0);
}
