/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 13:45:49 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/08/08 16:49:32 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_check_sort(t_pile *a)
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

int		ft_inv_sort(t_pile *ptr)
{
	int nb;

	nb = ptr->nb;
	if (ptr->next)
	ptr = ptr->next;
	while (ptr->next != NULL)
	{
		if (ptr->nb < nb)
			return (0);
		ptr = ptr->next;
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

int		ft_is_min(t_pile *ptr)
{
	int nb;
	int i;
	int j;

	i = 0;
	j = 0;
	nb = ptr->nb;
	while (ptr->next != NULL)
	{
		if (ptr->nb < nb)
		{
			nb = ptr->nb;
			i = j;
		}
		ptr = ptr->next;
		j++;
	}
	return (i);
}

int		ft_algo(t_pile *a, t_pile *b)
{
	int	nb_operation;
	int	tmp;

	tmp = a->nb;
	nb_operation = 0;
	while (ft_check_sort(a) == 0)
	{
		if (ft_is_min(a) == 1)
		{
			ft_s_operation(a);
			nb_operation += 2;
			ft_putstr("sa\n");
			ft_p_operation(&a, &b);
			ft_putstr("pb\n");
		}
		while ((tmp = ft_is_min(a) != 0))
		{
		if (tmp > ft_lst_len(a) / 2)
		{
			nb_operation++;
			ft_revr_operation(&a);
			ft_putstr("rra\n");
		}
		else
		{
			nb_operation++;
			ft_r_operation(&a);
			ft_putstr("ra\n");
		}
		}
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
	ft_display_stacks(a, b);
	ft_putstr("\nNB OPERATIONS :");
	return (nb_operation);
}
