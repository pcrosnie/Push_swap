/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 11:12:09 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/08/18 14:22:06 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		*ft_int_dup_nf(int *str, int len)
{
	int i;
	int *cpy;

	i = 0;
	cpy = (int *)malloc(sizeof(int) * (len + 1));
	while (i < len)
	{
		cpy[i] = str[i];
		i++;
	}
	free(str);
	return (cpy);
}

int		ft_find_smaller_after(int *str, int i, t_pile *a)
{
	int nb;
	int start;

	start = str[0];
	nb = str[i];
	while (i < ft_lst_len(a))
	{
		if (str[i] > start && str[i] < nb)
			return (1);
		i++;
	}
	return (0);
}

void	ft_find_suit(int **tab, t_data *ptr, int step)
{
	int i;
	
		
	
}

int		ft_check_pos_suit(t_pile *a, t_data *ptr)
{
	int **tab;
	int *str;
	int ret;
	int i;

	i = 0;
	tab = (int **)malloc(sizeof(int *) * 2);
	ptr->record_ret = 0;
	str = ft_set_str(a);
	tab[0] = str;
	tab[1] = (int *)malloc(sizeof(int ) * (ft_lst_len(a) + 1));
	tab[1] = ft_memset(tab[1], '\0', ft_lst_len(a) + 1);
	ft_find_suit(str, ptr);
	
	
}

int		ft_algo(t_pile *a, t_pile *b)
{
	int	nb_operation;
	int	*str;
	int lim;
	t_data *ptr;

	ptr = (t_data *)malloc(sizeof(t_data) * 5);
	nb_operation = 0;
	ft_lst_len(b);
	str = ft_check_pos_suit(a, &lim, 0);
	ft_print_int_tab(str, lim);
	return (0);
}
