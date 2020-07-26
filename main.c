/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 13:12:18 by tmendes-          #+#    #+#             */
/*   Updated: 2020/07/26 10:23:20 by tmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"


static long int *hold_null(long int * p_int, int pos)
{
	long int	*p_aux;
	long int	k;

	k = 0;
	p_aux = p_int;
	if (!p_int)
	{
		if(!(p_int = (long int *)malloc(2 * sizeof(long int))))
			return (NULL);
		*p_int = pos;
		*(p_int + 1) = -1;
	}
	else
	{
		while (*(p_int + k) != -1)
			k++;
		if (!(p_int = (long int *)malloc((k + 2) * sizeof(long int))))
			return (NULL);
		*(p_int + k + 1) = -1;
		*(p_int + k) = pos;
		while (--k >= 0)
			*(p_int + k) = *(p_aux + k);
		free(p_aux);
	}
	return (p_int);
}


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

	long int		*pint;
	int		pk;

	pint = NULL;
	pk = 0;

	pint = hold_null(pint, 3);
	pint = hold_null(pint, 528);
	pint = hold_null(pint, 2);
	pint = hold_null(pint, 435);
	printf("\n");
	while (*(pint + pk) != -1)
	{
		printf("%ld ", *(pint + pk));
		pk++;
	}
	printf("\n");
	
	free(pint);
	pint = NULL;
	printf("\n");
	//ptf1 = printf("%c, %-*c", 0, 0, 0); //T2
	ptf1 = printf("%c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %c %c %c %c %c %c %c %c %c %c %c %c %c", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0); //T2
	//ptf1 = printf("%c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %-*c, %-*c, %*c, %*c", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0); //T2
	printf(" %d", ptf1); //T2
	printf("\n");

	printf("\n");
	//ptf2 = ft_printf("%c, %-*c", 0, 0, 0); //T2
	ptf2 = ft_printf("%c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %c %c %c %c %c %c %c %c %c %c %c %c %c", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0); //T2
	//ptf2 = ft_printf("%c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %-*c, %-*c, %*c, %*c", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0); //T2
	printf(" %d", ptf2); //T2
	printf("\n");

	return(0);
}
