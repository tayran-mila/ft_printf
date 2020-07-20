/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scntfc_not.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 08:30:10 by tmendes-          #+#    #+#             */
/*   Updated: 2020/07/20 12:56:14 by tmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	nbr_exp(long double nbr)
{
	int			nbr_i;
	int			k;

	if (1/nbr < 0)
		nbr = -nbr;
	if(nbr == 0)
		return (0);
	else if (nbr >= 1)
		return ( (nbr_digit(nbr) - 1));
	else
	{
		k = 0;
		nbr_i = (int)nbr;
		while (nbr_i == 0)
		{
			k--;
			nbr_i = (int)(10*nbr);
			nbr = (10*nbr) - (long double)nbr_i;
		}
		return (k);
	}
}

char	*unpad(char *nbr, char chr)
{
	int		k;
	char	*exp;

	exp = ft_strchr(nbr, 'e');
	k = ft_strlen(nbr) - 1;
	if (chr == 'e')
	{
		k -= ft_strlen(exp);
		while ((*(nbr + k) == '0' || *(nbr + k) == '.') &&
		k > 0 && *(nbr + (k - 1)) != '-')
			k--;
		ft_memmove((nbr + k + 1), exp, ft_strlen(exp) + 1);
	}
	else
	{
		while (*(nbr + k) == '0' && k > 0 && *(nbr + (k - 1)) != '-')
			k--;
		if ( *(nbr + k) == '.')
			*(nbr + k) = 0;
		*(nbr + k + 1) = 0;
	}
	return (nbr);
}

static char	*p_exp(char *nbr, int prec)
{
	char	*exp;
	int		k;
	char	chr;

	k = 1;
	while ( *(nbr + k) != '.')
		k++;
	ft_memmove((nbr + k), (nbr + k + 1), prec + 2);
	chr = *(nbr + prec + 2);
	*(nbr + prec + 2) = 0;
	if ( chr >= '5')
		nbr = round_str(nbr);
	if (*nbr == '0')
	{
		nbr = ft_memmove(nbr, (nbr + 1), prec + 2);
		k--;
	}
	else
		*(nbr + prec + 1) = 0;
	ft_memmove((nbr + 2), (nbr + 1), prec + 1);
	*(nbr + 1) = '.';
	nbr = join_ptr(nbr,"e+");
	k--;
	if (k < 10)
		nbr = join_ptr(nbr,"0");
	exp = ft_llitoa(k, 10, 'a');
	nbr = join_ptr(nbr, exp);
	free(exp);
	exp = NULL;
	return (nbr);
}

static char	*n_exp(char *nbr, int prec)
{
	char	*point;
	char	*exp;
	int		k;
	char	chr;

	point = ft_strchr(nbr, '.');
	k = 1;
	while ( *(point + k) == '0')
		k++;
	if ( *(point + k) == 0)
	{
		*(nbr + prec + 2) = 0;
		nbr = join_ptr(nbr,"e+00");
		return (nbr);
	}
	nbr = ft_memmove(nbr, (point + k), prec + 2);
	chr = *(nbr + prec + 1);
	*(nbr + prec + 1) = 0;
	if ( chr >= '5')
		nbr = round_str(nbr);
	ft_memmove((nbr + 2), (nbr + 1), prec + 1);
	*(nbr + 1) = '.';
	nbr = join_ptr(nbr,"e-");
	if (k < 10)
		nbr = join_ptr(nbr,"0");
	exp = ft_llitoa(k, 10, 'a');
	nbr = join_ptr(nbr, exp);
	free(exp);
	exp = NULL;
	return (nbr);
}

char	*scntfc_not(char *nbr, int prec)
{
	char *aux;

	if (*nbr == '0')
	{
		nbr = n_exp(nbr, prec);
		return (nbr);
	}
	else
	{	aux = ft_strdup("0");
		aux = join_ptr(aux, nbr);
		aux = p_exp(aux, prec);
		free (nbr);
		nbr = NULL;
		return (aux);
	}
}