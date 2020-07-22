/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 09:54:30 by tmendes-          #+#    #+#             */
/*   Updated: 2020/03/04 19:25:53 by tmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long	del_nbr(char const *s, char c)
{
	unsigned long	k;
	unsigned long	del;

	if (s == NULL)
		return (0);
	k = 0;
	del = 0;
	while (*(s + k) != 0)
	{
		if (*(s + k) == c)
			del++;
		k++;
	}
	return (del + 1);
}

static unsigned long	*del_idx(char const *s, char c)
{
	unsigned long	*p;
	unsigned long	k;
	unsigned long	del;

	if (s == NULL)
		return (NULL);
	if ((!(p = (unsigned long *)malloc((del_nbr(s, c) + 1)
	* sizeof(unsigned long)))))
		return (NULL);
	*p = 0;
	k = 0;
	del = 1;
	while (*(s + k) != 0)
	{
		if (*(s + k) == c)
		{
			*(p + del) = k + 1;
			del++;
		}
		k++;
	}
	*(p + del) = k + 1;
	return (p);
}

char					**ft_split(char const *s, char c)
{
	char			**p;
	unsigned long	k;
	unsigned long	row;
	unsigned long	*idx;

	if (s == NULL)
		return (NULL);
	idx = (unsigned long *)del_idx(s, c);
	if (!(p = (char **)malloc((del_nbr(s, c) + 1)
	* sizeof(char *))) || s == NULL)
		return (NULL);
	k = 0;
	row = 0;
	while (k < del_nbr(s, c))
	{
		if (idx[k + 1] - idx[k] > 1)
		{
			p[row] = ft_substr(s, idx[k], (idx[k + 1] - idx[k] - 1));
			row++;
		}
		k++;
	}
	p[row] = NULL;
	free(idx);
	return (p);
}
