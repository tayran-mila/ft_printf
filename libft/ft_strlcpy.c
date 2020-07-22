/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:47:15 by tmendes-          #+#    #+#             */
/*   Updated: 2020/03/04 15:06:51 by tmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned long	k;

	if (dst == NULL || src == NULL)
		return (0);
	if (size > 0)
	{
		k = 0;
		while (*(src + k) != 0 && k < (size - 1))
		{
			*(dst + k) = *(src + k);
			k++;
		}
		*(dst + k) = 0;
	}
	return (ft_strlen(src));
}
