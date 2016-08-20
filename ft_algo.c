/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 11:12:09 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/08/20 15:57:45 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



int		ft_find_next_min(int *str, t_pile *a, int tmp2)
{
	int i;
	int step;
	int tmp;

	i = 0;
	step = 0;
	tmp = str[0];
	while (tmp <= tmp2)
	{
		tmp = str[i++];
	}
	i = 0;
	while (i < ft_lst_len(a))
	{
		if (str[i] <= tmp && str[i] > tmp2)
		{
			tmp = str[i];
			step = i;
		}
		i++;
	}
	return (step);
}

int		ft_find_min(int *str, t_pile *a)
{
	int i;
	int step;
	int tmp;

	i = 0;
	step = 0;
	tmp = str[0];
	while (i < ft_lst_len(a))
	{
		if (str[i] < tmp)
		{
			tmp = str[i];
			step = i;
		}
		i++;
	}
	return (step);
}

int		ft_search(int *str, int nb, int i, int len)
{
	while (i < len)
	{
		if (nb == str[i])
			return (i);
		i++;
	}
	return (0);
}

int		ft_find_greatest_suit(int **str, t_data *ptr, int i, int nb_cherche)
{
	ft_putnbr(ptr->now_record);
	ft_putchar('\n');
	ptr->i_tmp = i;
	if (ptr->now_record > ptr->record_ret)
		ptr->record_ret = ptr->now_record;
	if ((i >= ptr->lst_len - 1 && nb_cherche == ptr->lst_len) || i < 0)
		return (0);
	i = ft_search(str[1], nb_cherche, i, ptr->lst_len);	
	if (i > 0)
	{
		ft_putchar('A');
		ptr->now_record++;
		ft_find_greatest_suit(str, ptr, i + 1, nb_cherche + 1);
	}
	else if (nb_cherche >= ptr->lst_len)
	{
		ft_putchar('B');
		ft_find_greatest_suit(str, ptr, i, nb_cherche + 1);
	}
	else
	{
		ft_putchar('C');
		ptr->now_record--;
		ft_find_greatest_suit(str, ptr, ptr->i_tmp - 1, str[i][ptr->i_tmp] + 1);
	}
	return (0);
}

void	ft_check_pos_suit(t_pile *a, t_data *ptr, int j)
{
	int **str;
	int tmp;
	int step;
	int i;

	step = 1;
	ptr->lst_len = ft_lst_len(a);
	str = (int **)malloc(sizeof(int *) * 2);
	str[0] = ft_set_str(a);
	str[1] = (int *)malloc(sizeof(int) * (ft_lst_len(a) + 1));
	str[1] = (int *)ft_memset(str[1], 0, (ft_lst_len(a) + 1));
	i = ft_find_min(str[0], a);
	tmp = str[0][i];
	str[1][i] = step++;
	i = 0;
	j = 1;
	while (j < ft_lst_len(a))
	{
//		ft_putnbr(tmp);
//		ft_putchar('\n');
		i = ft_find_next_min(str[0], a, tmp);
		tmp = str[0][i];
		str[1][i] = step++;
		j++;
	}
//	ft_putstr("here\n");
	ft_find_greatest_suit(str, ptr, 1, 2);
//	ft_print_int_tab(str[0], ft_lst_len(a));
//	ft_print_int_tab(str[1], ft_lst_len(a));
}

int		ft_algo(t_pile *a, t_pile *b)
{
	int	nb_operation;
	t_data *ptr;

	ptr = (t_data *)malloc(sizeof(t_data) * 5);
	ptr->record_suit = (int *)malloc(sizeof(int) * (ft_lst_len(a) + 1));
	ptr->record_ret = 0;
	ptr->now_record = 0;
	nb_operation = 0;
	ft_lst_len(b);
	ft_check_pos_suit(a, ptr, 0);
//	ft_print_int_tab(str, lim);
	return (0);
}
