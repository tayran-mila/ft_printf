/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmendes- <tmendes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 13:12:18 by tmendes-          #+#    #+#             */
/*   Updated: 2020/07/29 07:15:49 by tmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

int main()
{
static char 		ch_pos_1 = 100, ch_neg_1 = -87;
static short		sh_pos_1 = 3047, sh_neg_1 = -8875;
static int			i_pos_1 = 878023;
static long			l_pos_1 = 22337203685477, l_neg_1 = -22337203685477;
static long long	ll_pos_1 = 22337203685477, ll_neg_1 = -22337203685477;
static long			lmax	= 9223372036854775807;
static long			lmin	= -9223372036854775807;
static long long	llmax = 9223372036854775807;
static long long	llmin = -9223372036854775807ll;

int ptf1;
int ptf2;

	
	printf("\n");
	ptf1 = printf("%.7e", 23.375094499);
	//ptf1 = printf("%ld %hhd %hd", l_neg_1, ch_pos_1, sh_pos_1);
	//ptf1 = printf("%lli %d %ld", ll_neg_1, i_pos_1, l_pos_1);
	//ptf1 = printf("%li %hhi %hi", l_neg_1, ch_pos_1, sh_pos_1);
	//ptf1 = printf("%lli %i %li", ll_neg_1, i_pos_1, l_pos_1);
	printf(" %d", ptf1);
	printf("\n");

	printf("\n");
	ptf2 = ft_printf("%.7e", 23.375094499);
	//ptf2 = ft_printf("%ld %hhd %hd", l_neg_1, ch_pos_1, sh_pos_1);
	//ptf2 = ft_printf("%lli %d %ld", ll_neg_1, i_pos_1, l_pos_1);
	//ptf2 = ft_printf("%li %hhi %hi", l_neg_1, ch_pos_1, sh_pos_1);
	//ptf2 = ft_printf("%lli %i %li", ll_neg_1, i_pos_1, l_pos_1);
	printf(" %d", ptf2);
	printf("\n");

	return(0);
}
