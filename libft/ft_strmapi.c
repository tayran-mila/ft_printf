/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 19:13:56 by tmendes-          #+#    #+#             */
/*   Updated: 2020/03/03 18:48:07 by tmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*p;
	unsigned int	k;

	if (!s)
		return (NULL);
	if (!(p = (char *)malloc((ft_strlen(s) + 1) * sizeof(char))))
		return (NULL);
	k = 0;
	while (*(s + k) != 0)
	{
		*(p + k) = f(k, *(s + k));
		k++;
	}
	*(p + k) = 0;
	return (p);
}
