/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:28:05 by tmendes-          #+#    #+#             */
/*   Updated: 2020/03/01 15:11:26 by tmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned long k;

	k = 0;
	while (k < n)
	{
		if (*((char *)s1 + k) != *((char *)s2 + k))
			return ((unsigned char)*((char *)s1 + k)
			- (unsigned char)*((char *)s2 + k));
		else
			k++;
	}
	return (0);
}
