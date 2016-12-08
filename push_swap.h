/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/05 11:52:41 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/12/08 13:23:27 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "get_next_line.h"
# include <stdio.h>

typedef struct	s_pile
{
	int				nb;
	struct s_pile	*next;
}				t_pile;

typedef struct	s_data
{
	int i_tmp;
	int	now_record;
	int lst_len;
	int record_ret;
	int *record_suit;
}				t_data;

int				check_sort(t_pile *a);
void			solve(t_pile **a, t_pile **b, int left, int right);
int				get_value(int index, t_pile *a);
int				invers_pos(int index1, int index2, t_pile **a, t_pile **b);
void			ft_print_int_tab(int *str, int len);
int				*ft_set_str(t_pile *a);
int				ft_lst_len(t_pile *ptr);
int				ft_is_min(t_pile *ptr);
int				ft_inv_sort(t_pile *ptr);
int				ft_rr_operation(t_pile **a, t_pile **b);
int				ft_algo(t_pile *a, t_pile *b);
int				ft_algo2(t_pile *a, t_pile *b);
int				ft_s_operation(t_pile *ptr);
int				ft_ss_operation(t_pile *a, t_pile *b);
int				ft_p_operation(t_pile **src, t_pile **dst);
int				ft_r_operation(t_pile **ptr);
int				ft_r_or_rr(t_pile **a, int tmp);
void			ft_display_stacks(t_pile *a, t_pile *b);
int				ft_revr_operation(t_pile **ptr);
int				ft_revr_both_operation(t_pile **a, t_pile **b);

#endif
