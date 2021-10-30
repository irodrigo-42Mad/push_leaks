/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 13:22:05 by irodrigo          #+#    #+#             */
/*   Updated: 2021/10/29 13:22:08 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_primary.h"

void	ft_push_swap_tiny(t_element **a, t_element **b, int n_elm)
{
	if (n_elm <= 3)
		ft_srthree(a, b);
	else
	{
		ft_small_splb(a, b, n_elm);
		ft_srthree(a, b);
		ft_bk_split(a, b, ft_lstlength(*b));
	}
}

void	ft_push_swap_norm(t_element **a, t_element **b, int n_elm)
{
	if (n_elm > 20)
		ft_split_stkb(a, b, n_elm);
	else
		ft_splitrot_stkb(a, b, n_elm);
	ft_bk_split(a, b, ft_lstlength(*b));
	if ((*a)->n_val)
		ft_push_swap_norm(a, b, ft_segment_len(*a));
}
