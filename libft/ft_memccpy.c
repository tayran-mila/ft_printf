/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 16:27:35 by tmendes-          #+#    #+#             */
/*   Updated: 2020/03/01 15:06:06 by tmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned long	k;

	k = 0;
	while (k < n)
	{
		*((char *)dst + k) = (unsigned char)*((char *)src + k);
		if ((unsigned char)*((char *)src + k) == (unsigned char)c)
		{
			return (((char *)dst + k + 1));
		}
		k++;
	}
	return (NULL);
}
