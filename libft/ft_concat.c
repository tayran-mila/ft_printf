/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 20:22:54 by tmendes-          #+#    #+#             */
/*   Updated: 2020/08/02 14:53:56 by tmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_concat(char *s1, char const *s2)
{
	char			*p;
	unsigned long	len_1;
	unsigned long	size;
	unsigned long	k;

	if (!s1 || !s2)
	{
		if (s1)
			free(s1);
		return (NULL);
	}
	len_1 = ft_strlen(s1);
	size = len_1 + ft_strlen(s2);
	p = s1;
	if (!(s1 = (char *)malloc((size + 1) * sizeof(char))))
		return (NULL);
	k = -1;
	while (++k < len_1)
		*(s1 + k) = *(p + k);
	free(p);
	k--;
	while (++k < size)
		*(s1 + k) = *(s2 + k - len_1);
	*(s1 + k) = 0;
	return (s1);
}
