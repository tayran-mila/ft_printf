/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:08:15 by tmendes-          #+#    #+#             */
/*   Updated: 2020/03/01 15:28:38 by tmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned long k;

	k = 0;
	while (k <= ft_strlen(s))
	{
		if (*(s + k) == (char)c)
			return ((char *)(s + k));
		k++;
	}
	return (NULL);
}
