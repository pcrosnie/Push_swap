/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 13:45:49 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/12/08 11:52:23 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_sort(t_pile *a)
{
	int nb;

	nb = a->nb;
	if (a->next != NULL)
		a = a->next;
	while (a->next != NULL)
	{
		if (a->nb < nb)
			return (0);
		nb = a->nb;
		a = a->next;
	}
	return (1);
}

int		ft_lst_len(t_pile *ptr)
{
	int i;

	i = 0;
	while (ptr->next != NULL)
	{
		i++;
		ptr = ptr->next;
	}
	return (i);
}

int		ft_r_or_rr(t_pile **a, int tmp)
{
	t_pile *ptr;

	ptr = *a;
	if (tmp >= ft_lst_len(ptr) / 2)
	{
		ft_revr_operation(&ptr);
		ft_putstr("rra\n");
	}
	else
	{
		ft_r_operation(&ptr);
		ft_putstr("ra\n");
	}
	*a = ptr;
	return (1);
}

int		ft_sp_operation(t_pile **a, t_pile **b)
{
	t_pile *tmp;
	t_pile *tmp2;

	tmp = *a;
	tmp2 = *b;
	ft_s_operation(tmp);
	ft_putstr("sa\n");
	ft_p_operation(&tmp, &tmp2);
	ft_putstr("pb\n");
	*a = tmp;
	*b = tmp2;
	return (2);
}

int		ft_algo2(t_pile *a, t_pile *b)
{
	int	nb_operation;
	int	tmp;

	nb_operation = 0;
	while (check_sort(a) == 0)
	{
		if (ft_is_min(a) == 1)
			nb_operation += ft_sp_operation(&a, &b);
		while ((tmp = ft_is_min(a)))
			nb_operation += ft_r_or_rr(&a, tmp);
		ft_p_operation(&a, &b);
		nb_operation++;
		ft_putstr("pb\n");
	}
	while (b->next != NULL)
	{
		ft_p_operation(&b, &a);
		nb_operation++;
		ft_putstr("pa\n");
	}
//	ft_display_stacks(a, b);
	ft_putstr("\nNB OPERATIONS :");
	return (nb_operation);
}

int		ft_is_stack_min(int *str, int lim)
{
	int i;
	int tmp;

	i = 1;
	tmp = str[0];
	while (i < lim)
	{
		if (str[i] < tmp)
			tmp = str[i];
		i++;
	}
	i = 0;
	while (str[i] != tmp)
		i++;
	return (i);
}

void	ft_print_int_tab(int *str, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		ft_putnbr(str[i]);
		ft_putchar('\n');
		i++;
	}
}
/*
int		ft_find_med(t_pile *a, int *str)
{
	int	i;
	int j;
	int tmp;

	i = ft_lst_len(a) - 1;
	while (i >= ft_lst_len(a) / 2)
	{
		j = ft_is_stack_min(str, i);
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i--;
	}
	return (str[i + 1]);
}*/

int		*ft_set_str(t_pile *a)
{
	int i;
	int j;
	int *str;
	t_pile *tmp;

	tmp = a;
	i = 0;
	j = 0;
	str = (int *)malloc(sizeof(int) * (ft_lst_len(a) + 1));
	while (a->next != NULL)
	{
		str[i++] = a->nb;
		a = a->next;
	}
	return (str);
}
/*
int		ft_algo(t_pile *a, t_pile *b)
{
	int nb_operation;
	int	mediane;
	t_pile *tmp;

	tmp = b;
	nb_operation = 0;
	mediane = ft_set_med(a);
	ft_putnbr(mediane);
	ft_putchar('\n');
	return (0);	
}*/
