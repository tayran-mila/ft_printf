/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 08:01:58 by tmendes-          #+#    #+#             */
/*   Updated: 2020/03/04 16:07:50 by tmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(const char *str)
{
	int c;

	c = 0;
	while (str[c] != 0)
	{
		if (((str[c] >= '\t' && str[c] <= '\r') || str[c] == ' ') == 0)
			return (c);
		c++;
	}
	return (c);
}

static int	is_signal(const char *str)
{
	int c;

	c = is_space(str);
	while (str[c] != 0)
	{
		if ((str[c] == '+' || str[c] == '-') == 0)
			return (c);
		c++;
	}
	return (c);
}

static int	is_number(const char *str)
{
	int c;

	c = is_signal(str);
	while (str[c] != 0)
	{
		if ((str[c] >= '0' && str[c] <= '9') == 0)
			return (c);
		c++;
	}
	return (c);
}

int			ft_atoi(const char *str)
{
	int	ini;
	int	fin;
	int	nbr;

	if ((is_signal(str) - is_space(str)) > 1)
		return (0);
	else
	{
		ini = is_signal(str);
		fin = is_number(str);
		nbr = 0;
		while (ini <= fin)
		{
			if (str[ini] >= '0' && str[ini] <= '9')
				nbr = nbr * 10 + (str[ini] - '0');
			ini++;
		}
		if (str[is_space(str)] == '-')
			nbr = -nbr;
		return (nbr);
	}
	return (0);
}
