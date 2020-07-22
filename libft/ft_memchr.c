/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:01:58 by tmendes-          #+#    #+#             */
/*   Updated: 2020/03/03 15:35:07 by tmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned long k;

	k = 0;
	while (k < n)
	{
		if (*((unsigned char *)s + k) == (unsigned char)c)
			return ((unsigned char *)s + k);
		k++;
	}
	return (NULL);
}
