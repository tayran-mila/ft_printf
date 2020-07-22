/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strround.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 08:40:23 by tmendes-          #+#    #+#             */
/*   Updated: 2020/07/22 09:30:19 by tmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strround(char *nbr)
{
	int	k;

	k = ft_strlen(nbr) - 1;
	while (k >= 0)
	{
		if (*(nbr + k) == '9')
		{
			*(nbr + k) = '0';
			k--;
		}
		else
		{
			*(nbr + k) = *(nbr + k) + 1;
			return (nbr);
		}
	}
	return (nbr);
}
