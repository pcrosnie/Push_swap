/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 16:23:59 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/12/07 11:41:15 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_display_stacks(t_pile *a, t_pile *b)
{
	if (a)
	{
		ft_putstr("pile A :\n");
		while (a->next != NULL)
		{
			ft_putnbr(a->nb);
			ft_putchar('\n');
			a = a->next;
		}
	}
	if (b)
	{
		ft_putstr("pile B:\n");
		while (b->next != NULL)
		{
			ft_putnbr(b->nb);
			ft_putchar('\n');
			b = b->next;
		}
	}
}

int		ft_check_sort(t_pile *a, t_pile *b)
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
	if (b->next != NULL)
		return (0);
	return (1);
}

void	ft_set_operation(char *str, t_pile **ta, t_pile **tb)
{
	t_pile	*a;
	t_pile	*b;
	int		tmp;

	a = *ta;
	b = *tb;
	tmp = 0;
	(ft_strequ(str, "ra") == 1) ? ft_r_operation(&a) : tmp++;
	(ft_strequ(str, "rb") == 1) ? ft_r_operation(&b) : tmp++;
	(ft_strequ(str, "rr") == 1) ? ft_rr_operation(&a, &b) : tmp++;
	(ft_strequ(str, "rra") == 1) ? ft_revr_operation(&a) : tmp++;
	(ft_strequ(str, "rrb") == 1) ? ft_revr_operation(&b) : tmp++;
	(ft_strequ(str, "rrr") == 1) ? ft_revr_both_operation(&a, &b) : tmp++;
	(ft_strequ(str, "sa") == 1) ? ft_s_operation(a) : tmp++;
	(ft_strequ(str, "sb") == 1) ? ft_s_operation(b) : tmp++;
	(ft_strequ(str, "ss") == 1) ? ft_ss_operation(a, b) : tmp++;
	(ft_strequ(str, "pa") == 1) ? ft_p_operation(&b, &a) : tmp++;
	(ft_strequ(str, "pb") == 1) ? ft_p_operation(&a, &b) : tmp++;
	*ta = a;
	*tb = b;
	if (tmp == 11)
		ft_putstr("Invalid\n");
}

void	ft_set_stack(int argc, char **argv, t_pile *a)
{
	int i;

	i = 1;
	while (i < argc)
	{
		a->nb = ft_atoi(argv[i]);
		a->next = (t_pile *)ft_memalloc(sizeof(t_pile) * 10);
		a = a->next;
		i++;
	}
	a = NULL;
}

int		main(int argc, char **argv)
{
	char	*str;
	t_pile	*a;
	t_pile	*b;

	a = (t_pile *)malloc(sizeof(t_pile) * 10);
	b = (t_pile *)malloc(sizeof(t_pile) * 10);
	ft_set_stack(argc, argv, a);
	while (get_next_line(0, &str))
		ft_set_operation(str, &a, &b);
	if (ft_check_sort(a, b) == 0)
		ft_putstr("KO\n");
	else
		ft_putstr("OK\n");
	return (0);
}
