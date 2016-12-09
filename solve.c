/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 15:32:29 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/12/08 16:11:45 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		partition(t_pile **a, t_pile **b, int left, int right)
{
	int i;
	int j;
	int pivot;
	int h;

	i = left;
	j = right;
	h = ft_lst_len(*a);
	pivot = get_value((j + i) / 2, *a);
	while (i <= j)
	{
		while (get_value(i, *a) < pivot)
			i++;
		while (get_value(j, *a) > pivot)
			j--;
		if (i <= j)
		{
/*			ft_putstr("LEN:");
			ft_putnbr(h);
			ft_putchar('\n');
			ft_putstr("PIVOT:");
			ft_putnbr(pivot);
			ft_putstr("I:");
			ft_putnbr(i);
			ft_putstr("J:");
			ft_putnbr(j);
			ft_putchar('\n');*/
			invers_pos(i, j, a, b);
	//		ft_display_stacks(*a, *b);
			i++;
			j--;
		}
	}
//	printf("I %d\n", i);
	return (i);
}

void	solve(t_pile **a, t_pile **b, int left, int right)
{
	int index;

	index = partition(a, b, left, right);
//	printf("IN SOLVE index: %d left : %d right : %d\n", index, left, right);
	if (left < index)
	{
		solve(a, b, index, right);
	}
	if (index < right)
	{
//		ft_putstr("SECOND\n");
		solve(a, b, left, index);
	}
}
