/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llabs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 07:53:22 by tmendes-          #+#    #+#             */
/*   Updated: 2020/07/23 12:13:20 by tmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long int	ft_llabs(long long int j)
{
	if (j < 0)
		j = -j;
	return (j);
}
