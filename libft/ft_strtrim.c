/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 08:32:12 by tmendes-          #+#    #+#             */
/*   Updated: 2020/03/01 17:54:27 by tmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long	l_count(char const *s1, char const *set)
{
	unsigned long k;

	k = 0;
	while (*(s1 + k) != 0)
	{
		if (ft_strchr(set, *(s1 + k)) == NULL)
			return (k);
		k++;
	}
	return (k);
}

static unsigned long	r_count(char const *s1, char const *set)
{
	unsigned long	k;
	unsigned long	len;

	k = 0;
	len = ft_strlen(s1);
	while (*(s1 + k) != 0)
	{
		if (ft_strchr(set, *(s1 + len - 1 - k)) == NULL)
			return (k);
		k++;
	}
	return (k);
}

char					*ft_strtrim(char const *s1, char const *set)
{
	char			*p;
	unsigned long	l_c;
	unsigned long	r_c;
	unsigned long	len;

	if (!s1 || !set)
		return (NULL);
	l_c = l_count(s1, set);
	r_c = r_count(s1, set);
	len = ft_strlen(s1);
	if ((l_c + r_c) >= len)
		return (ft_strdup(""));
	if (!(p = ft_substr(s1, l_c, len - l_c - r_c)))
		return (NULL);
	return (p);
}
