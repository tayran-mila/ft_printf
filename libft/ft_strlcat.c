/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 14:12:44 by tmendes-          #+#    #+#             */
/*   Updated: 2020/03/03 18:06:52 by tmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned long	k;
	unsigned long	size_d;
	unsigned long	size_s;

	size_d = ft_strlen(dst);
	size_s = ft_strlen(src);
	if (dstsize >= size_d)
	{
		k = size_d;
		while (*(src + k - size_d) != 0 && k < (dstsize - 1))
		{
			*(dst + k) = *(src + k - size_d);
			k++;
		}
		*(dst + k) = 0;
		return (size_s + size_d);
	}
	else
		return (size_s + dstsize);
}
