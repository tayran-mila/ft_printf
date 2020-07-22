/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 15:19:32 by tmendes-          #+#    #+#             */
/*   Updated: 2020/03/04 15:56:19 by tmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *need, size_t n)
{
	long long		k;
	unsigned long	size_n;

	if (hay == NULL)
		*(char *)hay = 0;
	size_n = ft_strlen(need);
	k = 0;
	while (k <= (long long)(n - size_n))
	{
		if (ft_strncmp(hay + k, need, size_n) == 0)
			return ((char *)hay + k);
		k++;
	}
	return (NULL);
}
