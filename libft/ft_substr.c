/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 19:25:48 by tmendes-          #+#    #+#             */
/*   Updated: 2020/03/07 17:53:16 by tmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long	min(unsigned long a, unsigned long b)
{
	if (a >= b)
		return (b);
	else
		return (a);
}

char					*ft_substr(char const *s,
						unsigned int start, size_t len)
{
	char			*p;
	unsigned long	min_s;
	unsigned long	k;

	if (s == NULL)
		return (NULL);
	if ((unsigned long)start >= ft_strlen(s))
		min_s = 0;
	else
		min_s = min(ft_strlen(s) - start, len);
	if (!(p = (char *)malloc((min_s + 1) * sizeof(char))))
		return (NULL);
	k = 0;
	while (k < min_s)
	{
		*(p + k) = *(s + k + (unsigned long)start);
		k++;
	}
	*(p + k) = 0;
	return (p);
}
