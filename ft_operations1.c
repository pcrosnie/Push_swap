/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/05 13:45:34 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/12/08 15:56:13 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_s_operation(t_pile *ptr)
{
	int	tmp;

	tmp = ptr->nb;
	if (!(ptr->next))
		return (-1);
	ptr->nb = ptr->next->nb;
	ptr->next->nb = tmp;
	return (0);
}

int		ft_ss_operation(t_pile *a, t_pile *b)
{
	ft_s_operation(a);
	ft_s_operation(b);
	return (0);
}

int		ft_p_operation(t_pile **src, t_pile **dst)
{
	t_pile *tmp;
	t_pile *tmp2;

	if (!*src)
		return (0);
	tmp = *src;
	tmp2 = *src;
	if (!tmp->next)
		return (0);
	tmp = tmp->next;
	tmp2->next = *dst;
	*dst = tmp2;
	*src = tmp;
	return (0);
}

int		ft_r_operation(t_pile **ptr)
{
	t_pile *tmp;
	t_pile *tmp2;

	tmp = *ptr;
	tmp2 = *ptr;
	*ptr = tmp->next;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->nb = tmp2->nb;
	tmp->next = tmp2;
	tmp2->next = NULL;
	return (0);
}

int		ft_rr_operation(t_pile **a, t_pile **b)
{
	ft_r_operation(a);
	ft_r_operation(b);
	return (0);
}
