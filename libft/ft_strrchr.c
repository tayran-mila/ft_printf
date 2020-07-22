/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 14:14:28 by tmendes-          #+#    #+#             */
/*   Updated: 2020/03/03 16:01:25 by tmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned long	k;
	unsigned long	len;

	k = 0;
	len = ft_strlen(s);
	while (k <= len)
	{
		if (*(s + len - k) == (char)c)
			return ((char *)(s + len - k));
		k++;
	}
	return (NULL);
}
