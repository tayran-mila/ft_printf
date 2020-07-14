/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 13:12:18 by tmendes-          #+#    #+#             */
/*   Updated: 2020/07/14 13:14:30 by tmendes-         ###   ########.fr       */
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

	//nbr = -0000000.00000012345671234567898760000000001234567890;
	nbr = -0.0;

	dig = 3;
	str = ft_ftoa(nbr, 150);
	str++;
	dig = 1;
	dig++;
	
	num = (int)nbr;
	chr = 'T';
	ptr = &chr;
	iptr = &nptr;
	print1 = printf("\nOr_Printf: %% hexa: %d \\o/ %n%p %e", num, iptr, ptr, nbr);
	printf(" %d\n",print1);
	*iptr = 0;
	print2 = ft_printf("\nFt_Printf: %% hexa: %d \\o/ %n%p %.3e", num, iptr, ptr, nbr);
	printf(" %d\n\n",print2);
	return(0);
}










/*static t_llint	pot_b(t_llint nbr, int base)
{
	t_llint	pot;

	if (nbr <= 0)
		pot = 1;
	else
		pot = base * pot_b(nbr - 1, base);
	return (pot);
}

typedef union {
  float f;
  struct {
    unsigned int mantisa : 23;
    unsigned int exponent : 8;
    unsigned int sign : 1;
  } parts;
} float_cast;


int main(void)
{
	t_llint value;
	int i;
	long double result;
	long double mult;
	char	*final;
	//t_llint cast;


	float_cast d1 = { .f = 0.12345678901234567890 };
	printf("sign = %d\n", d1.parts.sign);
	printf("exponent = %d\n", d1.parts.exponent);
	printf("mantisa = %d\n", d1.parts.mantisa);
	printf("float1 = %.3f\n", d1.f);
	//d1.parts.exponent++;
	//printf("float1 = %f\n", d1.f);

	value = (t_llint)d1.parts.mantisa;


	i = 22;
	result = 1;
	mult = 2;
	while (i >= 0)
	{
		if ((value & pot_b(i, 2)) == pot_b(i, 2))
		{
			//printf("%lld\n", pot_b(i, 2));
			result += 1 / mult;
		}
		mult *= 2;
		i--;
	}

	result *= (long double)pot_b(d1.parts.exponent - 127, 2);
	result *= (long double)pot_b(d1.parts.sign, -1);
	//cast = (t_llint)result;
	final = ft_llitoa((t_llint)result,10,'a');
	printf("result = %.Lf\n", result);
	printf("float2 = %s\n", final);
	return (0);
}*/
