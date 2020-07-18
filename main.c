/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 13:12:18 by tmendes-          #+#    #+#             */
/*   Updated: 2020/07/18 08:07:59 by tmendes-         ###   ########.fr       */
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
	nbr = 12385678900000000000000000000000000000000000000000.0;
	//nbr = 999699.0000;
	//nbr = -100000000000000000000000000000000000000000.0000;

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
	print1 = printf("\nOr_Printf: %% hexa: %d \\o/ %n%p %.15g", num, iptr, ptr, nbr);
	printf(" %d\n",print1);
	print2 = ft_printf("\nFt_Printf: %% hexa: %d \\o/ %n%p %.15g", num, iptr, ptr, nbr);
	printf(" %d\n\n",print2);
	return(0);
}
