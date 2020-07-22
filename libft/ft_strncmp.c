/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 15:01:43 by tmendes-          #+#    #+#             */
/*   Updated: 2020/07/02 08:36:49 by tmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned long k;

	k = 0;
	while (k < n && (*(s1 + k) != 0 || *(s2 + k) != 0))
	{
		if (*(s1 + k) != *(s2 + k))
		{
			return (*((unsigned char *)s1 + k)
			- *((unsigned char *)s2 + k));
		}
		k++;
	}
	return (0);
}
