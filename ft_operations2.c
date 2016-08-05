/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/05 15:48:10 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/08/05 16:00:17 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_revr_operation(t_pile **ptr)
{
	t_pile *tmp;
	t_pile *tmp2;
	int	a;

	a = 0;
	tmp = *ptr;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tmp2 = tmp;
	a = tmp->nb;
	tmp = tmp->next;
	tmp2->next = NULL;
	tmp->next = *ptr;
	tmp->nb = a;
	*ptr = tmp;
	return (0);
}

int		ft_revr_both_operation(t_pile **a, t_pile **b)
{
	ft_revr_operation(a);
	ft_revr_operation(b);
	return (0);
}
