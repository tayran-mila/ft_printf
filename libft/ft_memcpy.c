/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:36:28 by tmendes-          #+#    #+#             */
/*   Updated: 2020/03/03 15:53:27 by tmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned long	k;

	k = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (k < n)
	{
		*((unsigned char *)dst + k) =
		(unsigned char)*((char *)src + k);
		k++;
	}
	return (dst);
}
