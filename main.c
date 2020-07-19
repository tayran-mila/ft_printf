/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 13:12:18 by tmendes-          #+#    #+#             */
/*   Updated: 2020/07/19 16:48:26 by tmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

int main()
{
	//char	string[30] = "Printf";
  	int		num;
	int		print1;
	int		print2;
	char	chr;
	void	*ptr;
	int		*iptr;
	int		nptr;
	double	nbr;
	char	*str;
	int 	dig;

	ptr = &nbr;

	//nbr = 12345678901234567890123456789012345678901234567890.1234567890;
	nbr = -1238567000000000000.0;
	nbr = 123;
	//nbr = -100000000000000000000000000000000000000000.0000;

	//str = repeat_chr('T', 7);
	//printf ("\n\nRepeat: %s\n\n", str);

	dig = nbr_exp(nbr);

	dig = 3;
	str = ft_ftoa(nbr, 150);
	str++;
	dig = 1;
	dig++;
	
	num = (int)nbr;
	chr = 'T';
	ptr = &chr;
	iptr = &nptr;
	dig = 20;
	*iptr = 0;
	//print1 = printf("\nOr_Printf: %% hexa: %015d \\o/ %n%p %+015.5e", num, iptr, ptr, nbr);
	//printf(" %d\n",print1);
	//print2 = ft_printf("\nFt_Printf: %% hexa: %d \\o/ %n%p %+015.5e", num, iptr, ptr, nbr);
	//printf(" %d\n\n",print2);
	print1 = printf("\nOr_Printf: %#.6g", nbr);
	printf(" %d\n",print1);
	print2 = ft_printf("\nFt_Printf: %#.6g", nbr);
	printf(" %d\n\n",print2);
	ptr++;
	num++;
	return(0);
}
