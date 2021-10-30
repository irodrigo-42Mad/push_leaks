/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 14:38:32 by irodrigo          #+#    #+#             */
/*   Updated: 2021/10/29 14:38:47 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_primary.h"

static void	ft_axis_rot_max(t_element **a, t_element **b,
									t_element *max, int n_elm)
{
	t_element	*aux;
	int			x;

	x = 0;
	aux = *b;
	while (aux && aux->value != max->value)
	{
		aux = aux->next;
		x++;
	}
	if (x < n_elm / 2)
		rot_b(a, b, 1);
	else
		rot_rev_b(a, b, 1);
}

void	ft_splitrot_stkb(t_element **a, t_element **b, int n_elm)
{
	while (n_elm)
	{
		if ((*a)->n_val == 0 || (*a)->n_val == ft_lstgetlast(*a)->n_val + 1)
			rot_a(a, b, 1);
		else
			push_b(a, b, 1);
		n_elm--;
	}
}

void	ft_stack_bkrt(t_element **a, t_element **b, int n_elm)
{
	while (n_elm)
	{
		if (ft_max_min(*b))
			rot_rev_a(a, b, 1);
		else
			rot_rev_ab(a, b, 1);
		n_elm--;
	}
}

void	ft_rot_maxs(t_element **a, t_element **b)
{
	while ((*a)->next && (*a)->n_val == ft_lstgetlast(*a)->n_val + 1)
		rot_a(a, b, 1);
}

void	ft_setcntnt_back(t_element **a, t_element **b, int n_elm)
{
	t_element	*srt;
	t_element	*max;

	srt = ft_partial_sort(*b, n_elm);
	while (n_elm)
	{
		max = ft_lstgetlast(srt);
		if ((*b)->n_val == 0 || (*b)->n_val == ft_lstgetlast(*a)->n_val + 1)
		{
			push_a(a, b, 1);
			rot_a(a, b, 1);
			n_elm--;
		}
		else if ((*b)->value == max->value)
		{
			push_a(a, b, 1);
			lst_goto(srt, ft_lstlength(srt) - 2)->next = NULL;
			n_elm--;
		}
		else
			ft_axis_rot_max(a, b, max, n_elm);
	}
}
