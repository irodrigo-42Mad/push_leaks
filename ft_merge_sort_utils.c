/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_sort_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 13:51:19 by irodrigo          #+#    #+#             */
/*   Updated: 2021/10/29 13:51:29 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_primary.h"

t_element	*split_stk(t_element **stk, int n_elm)
{
	t_element	*aux;

	aux = NULL;
	while (n_elm)
	{
		push_b(stk, &aux, 0);
		n_elm--;
	}
	return (aux);
}

void	ft_stka_rm(t_element **a, t_element **b, int *a_len)
{
	rot_a(a, b, 0);
	*a_len -= 1;
}

void	ft_stkb_rm(t_element **a, t_element **b, int out)
{
	push_a(a, b, out);
	rot_a(a, b, out);
}

short	ft_strtwo(t_element **a, t_element **b)
{
	if (!(*a)->next && !(*b)->next)
	{
		if ((*a)->value < (*b)->value)
			ft_stkb_rm(a, b, 0);
		else
			push_a(a, b, 0);
		return (1);
	}
	return (0);
}
