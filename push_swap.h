/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/05 11:52:41 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/08/05 16:00:38 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct	s_pile
{
	int nb;
	struct s_pile *next;
}				t_pile;

int		ft_s_operation(t_pile *ptr);
int		ft_ss_opration(t_pile *a, t_pile *b);
int		ft_p_operation(t_pile **src, t_pile **dst);
int		ft_r_operation(t_pile **ptr);
void	ft_display_stacks(t_pile *a, t_pile *b);
int		ft_revr_operation(t_pile **ptr);
int		ft_revr_both_operation(t_pile **a, t_pile **b);

#endif
