/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/05 11:52:20 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/08/09 10:37:11 by pcrosnie         ###   ########.fr       */
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

int		ft_check_numbers(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0 && (argv[i][j] != '-' || j != 0))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_set_stack(int argc, char **argv, t_pile *a)
{
	int i;

	i = 1;
	while (i < argc)
	{
		a->nb = ft_atoi(argv[i]);
		a->next = (t_pile *)ft_memalloc(sizeof(t_pile) * argc);
		a = a->next;
		i++;
	}
	a = NULL;
}

int		ft_check_stack(t_pile *a)
{
	t_pile	*tmp;
	int		nb;

	tmp = a;
	nb = a->nb;
	if (a->next)
		a = a->next;
	while (tmp->next != NULL)
	{
		a = tmp;
		nb = a->nb;
		a = a->next;
		while (a->next != NULL)
		{
			if (a->nb == nb)
				return (0);
			a = a->next;
		}
		tmp = tmp->next;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	t_pile *a;
	t_pile *b;

	if (argc < 2 || ft_check_numbers(argc, argv) == 0)
		return (0);
	a = (t_pile *)ft_memalloc(sizeof(t_pile) * argc);
	b = (t_pile *)ft_memalloc(sizeof(t_pile) * argc);
	ft_set_stack(argc, argv, a);
	if (ft_check_stack(a) == 0)
	{
		ft_putstr("ERROR\n");
		return (0);
	}
	ft_putnbr(ft_algo(a, b));
	return (0);
}
