/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bkp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 13:12:18 by tmendes-          #+#    #+#             */
/*   Updated: 2020/07/10 19:19:28 by tmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"


/*static char	*join_ptr(char *dst, char *src)
{
	char	*join;

	join = dst;
	if (!(dst = (char *)ft_strjoin(join, src)))
		return (NULL);
	free(join);
	join = NULL;
	return (dst);
}

static char *round_str(char *final)
{
	int	k;

	k = ft_strlen(final) - 1;
	while (k >= 0)
	{
		if (*(final + k) == '9')
		{
			*(final + k) = '0';
			k--;
		}
		else
		{
			*(final + k) = *(final + k) + 1;
			return (final);
		}
	}
	return (final);
}

static char *fraction(long double nbr, int dig)
{
	long double	nbr_f;
	t_llint		nbr_i;
	char		*final;
	int			k;

	if(!(final = malloc((dig + 2) * sizeof(char))))
		return (NULL);
	nbr_i = (t_llint)nbr;
	nbr_f = nbr - (long double)nbr_i;
	*final = '0';
	k = 1;
	while (k <= dig + 1)
	{
		nbr_i = (t_llint)(10*nbr_f);
		*(final + k) = nbr_i + '0';
		nbr_f = (10*nbr_f) - (long double)nbr_i;
		k++;
	}
	*(final + dig + 1) = 0;
	if (nbr_i >= 5)
		final = round_str(final);
	return (final);
}

static int	nbr_digit(float nbr)
{
	int			dig;

	if (nbr < 0)
		nbr = -nbr;
	dig = 0;
	printf("\ndigit: %2d %f", dig, nbr);
	while (nbr >= 1)
	{
		dig++;
		nbr = (nbr/10);
		printf("\ndigit: %2d %f", dig, nbr);
	}
	if (dig == 0)
		dig++;
	return (dig);
}

static char *ft_ftoa(long double nbr, int dig)
{
	//t_llint		nbr_i;
	char		*final;
	char		*frctn;

	//nbr_i = (t_llint)nbr;
	final = ft_llitoa((t_llint)nbr, 10, 'a');
	frctn = fraction(nbr, dig);
	final = join_ptr(final, ".");
	final = join_ptr(final, (frctn + 1));
	return (final);

}

typedef union {
  float f;
  struct {
    unsigned int mantisa : 23;
    unsigned int exponent : 8;
    unsigned int sign : 1;
  } parts;
} float_cast;

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
	//double	nbr2;
	char	*flt;

	ptr = &nbr;

	nbr = 12345678901234567890.12345678901234567890;

	float_cast d1 = { .f = 25.0 };
	printf("sign = %d\n", d1.parts.sign);
	printf("exponent = %d\n", d1.parts.exponent);
	printf("mantisa = %d\n", d1.parts.mantisa);
	printf("float = %f\n", d1.f);
	d1.parts.exponent++;
	printf("float = %f\n", d1.f);



	flt = ft_ftoa(2.3,13);

	printf("\n\nAqui: %s\n\n", flt);
	
	num = (int)nbr;
	//nbr2 = nbr - (int)nbr;
	num = nbr_digit(nbr);
	chr = 'T';
	ptr = &chr;
	iptr = &nptr;
	print1 = printf("\n\nOr_Printf: %% hexa: %d \\o/ %n%p %.13f %ld \n\n", num, iptr, ptr, nbr, sizeof(nbr));
	printf("\n%d\n",print1);
	printf("\n%d\n",*iptr);
	*iptr = 0;
	print2 = ft_printf("\n\nFt_Printf: %% hexa: %d \\o/ %n%p \n\n",num, iptr, ptr);
	printf("\n%d\n",print2);
	printf("\n%d\n",*iptr);
	return(0);
}*/

static t_llint	pot_b(t_llint nbr, int base)
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
}

/*static int	nbr_digit(long double nbr)
{
	int			dig;

	if (nbr < 0)
		nbr = -nbr;
	dig = 0;
	printf("\ndigit: %2d %Lf", dig, nbr);
	while (nbr >= 1)
	{
		dig++;
		nbr = (nbr/10);
		printf("\ndigit: %2d %Lf", dig, nbr);
	}
	if (dig == 0)
		dig++;
	return (dig);
}

static long double	pot_b( long double base,  int exp)
{
	long double	pot;

	if (exp <= 0)
		pot = 1;
	else
		pot = base * pot_b(base, exp - 1);
	return (pot);
}

int main()
{

	double flo;
	int		dig;
	long double pot;
	long double aux;
	long double nbr_f;
	int nbr_i;

	flo = 123456789012345678901234567890123456789012345678901234567890.1234567890;
	dig = nbr_digit(flo);

	printf ("\n%.10f %ld %d\n", flo, sizeof(long double), dig);
	while (dig > 0)
	{
		pot = pot_b(10,dig-1);
		aux = flo/pot;
		nbr_i = (int)aux;
		flo = flo - nbr_i * pot;
		printf("%d",nbr_i);
		dig--;
	}

	printf ("\n%.10f %ld %d\n", flo, sizeof(long double), dig);
	printf ("\n%.10Lf %ld %d\n", pot, sizeof(long double), dig);

	return (0);
}*/