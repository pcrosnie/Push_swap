/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invert_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 12:14:35 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/12/07 14:45:51 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_value(int index, t_pile *a)
{
	t_pile *tmp;
	int i = 0;

	tmp = a;
	while (tmp->next)
	{
		if (index == i)
			return (tmp->nb);
		tmp = tmp->next;
		i++;
	}
	return (0);
}

int get_new_index(int value, t_pile *a)
{
	t_pile *tmp;
	int i = 0;

	tmp = a;
	while (tmp->next)
	{
		if (value == tmp->nb)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (0);
}

int invers_pos(int index1, int index2, t_pile **a, t_pile **b)
{
	int value1;
	int value2;
	int tmp_index;

	value1 = get_value(index1, *a);
//	ft_putstr("V1:");
//	ft_putnbr(value1);
	value2 = get_value(index2, *a);
	tmp_index = index2 - index1;
//	ft_putstr("V2:");
//	ft_putnbr(value2);
//	ft_putchar('\n');
	value2 = get_value(index2, *a);
	while (index1 != 0)
	{
		ft_r_or_rr(a, index1);
		index1 = get_new_index(value1, *a);
	}
	ft_p_operation(a, b);
	ft_putstr("pb\n");
	index2 = get_new_index(value2, *a);
	tmp_index = index2;
	while (index2 != 0)
	{
		ft_r_operation(a);
		index2 = get_new_index(value2, *a);
	}
	ft_p_operation(b, a);
	ft_putstr("pa\n");
	ft_r_operation(a);
	ft_putstr("ra\n");
	ft_p_operation(a, b);
	ft_putstr("pb\n");
	ft_revr_operation(a);
	ft_putstr("rra\n");
	while (tmp_index > 0)
	{
		ft_revr_operation(a);
		tmp_index--;
	}
	ft_display_stacks(*a, *b);
	ft_p_operation(b, a);
	ft_putstr("pa\n");
	return (0);
}
