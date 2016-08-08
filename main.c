/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/05 11:52:20 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/08/08 17:13:22 by pcrosnie         ###   ########.fr       */
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

int		main(int argc, char **argv)
{
	t_pile *a;
	t_pile *b;

	if (argc < 2 || ft_check_numbers(argc, argv) == 0)
		return (0);
	a = (t_pile *)ft_memalloc(sizeof(t_pile) * argc);
	b = (t_pile *)ft_memalloc(sizeof(t_pile) * argc);
	ft_set_stack(argc, argv, a);
//	ft_display_stacks(a, b);
	ft_putnbr(ft_algo(a, b));
//	ft_display_stacks(a, b);
	return (0);
}
