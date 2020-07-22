/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 20:22:54 by tmendes-          #+#    #+#             */
/*   Updated: 2020/03/03 15:08:47 by tmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*p;
	unsigned long	len_1;
	unsigned long	size;
	unsigned long	k;

	if (!s1 || !s2)
		return (NULL);
	len_1 = ft_strlen(s1);
	size = len_1 + ft_strlen(s2);
	if (!(p = (char *)malloc((size + 1) * sizeof(char))))
		return (NULL);
	k = 0;
	while (k < len_1)
	{
		*(p + k) = *(s1 + k);
		k++;
	}
	while (k < size)
	{
		*(p + k) = *(s2 + k - len_1);
		k++;
	}
	*(p + k) = 0;
	return (p);
}
