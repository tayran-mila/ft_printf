/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:08:42 by tmendes-          #+#    #+#             */
/*   Updated: 2020/03/04 16:20:48 by tmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*p;

	if (!(p = (char *)malloc((ft_strlen(s) + 1))))
		return (NULL);
	p = (char *)ft_memcpy(p, s, (ft_strlen(s) + 1));
	return (p);
}
