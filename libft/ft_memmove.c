/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:39:52 by tmendes-          #+#    #+#             */
/*   Updated: 2020/03/03 15:53:22 by tmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned long	k;

	k = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (k < len)
	{
		if (src >= dst)
			*((char *)dst + k) = (unsigned char)*((char *)src + k);
		else
			*((char *)dst + len - k - 1) =
			(unsigned char)*((char *)src + len - k - 1);
		k++;
	}
	return (dst);
}
