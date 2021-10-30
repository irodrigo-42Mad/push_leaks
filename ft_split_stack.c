/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 14:39:40 by irodrigo          #+#    #+#             */
/*   Updated: 2021/10/29 14:39:44 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_primary.h"

static t_element	*get_pivot(t_element **stack, int len)
{
	t_element	*sorted;
	t_element	*pivot;

	sorted = ft_partial_sort(*stack, len);
	pivot = lst_goto(sorted, len / 2);
	return (pivot);
}

void	ft_split_stkb(t_element **a, t_element **b, int len)
{
	t_element	*pivot;
	t_element	*limit;
	int			stack_len;
	int			rot;

	rot = 0;
	stack_len = ft_lstlength(*a);
	pivot = get_pivot(a, len);
	limit = NULL;
	while (ft_lstlength(*b) <= len / 2)
	{
		if ((*a)->chunk_limit)
			limit = (*a)->next;
		if ((*a)->value <= pivot->value)
			push_b(a, b, 1);
		else
		{
			if (len < stack_len)
				rot++;
			rot_a(a, b, 1);
		}
	}
	ft_stack_bkrt(a, b, rot);
	ft_new_sgm_limit(*a, limit);
}

void	ft_split_stka(t_element **a, t_element **b, int n_elm)
{
	t_element	*axis;
	int			lim_set;

	if (!(*b)->next)
	{
		push_a(a, b, 1);
		return ;
	}
	axis = get_pivot(b, n_elm);
	lim_set = 0;
	while ((*b) && ft_has_lftval(*b, axis))
	{
		if ((*b)->value > axis->value)
		{
			ft_set_sgm_limit(b, &lim_set);
			push_a(a, b, 1);
		}
		else
		{
			if ((*b)->n_val == 0 || (*b)->n_val == ft_lstgetlast(*a)->n_val + 1)
				ft_stkb_rm(a, b, 1);
			else
				rot_b(a, b, 1);
		}
	}
}

void	ft_bk_split(t_element **a, t_element **b, int n_elm)
{
	if (n_elm > 20)
	{
		ft_split_stka(a, b, n_elm);
		ft_bk_split(a, b, ft_lstlength(*b));
	}
	else if (n_elm)
	{
		ft_setcntnt_back(a, b, n_elm);
		ft_rot_maxs(a, b);
	}
}

void	ft_small_splb(t_element **a, t_element **b, int n_elm)
{
	short	limit;

	if (n_elm == 4)
		limit = 1;
	else
		limit = 2;
	while (ft_lstlength(*b) < limit)
	{
		if ((*a)->n_val <= 2)
			rot_a(a, b, 1);
		else
			push_b(a, b, 1);
	}
	if ((*b)->next && (*b)->value > ((t_element *)(*b)->next)->value)
		rot_b(a, b, 1);
}
