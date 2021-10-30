/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_seg_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 13:58:46 by irodrigo          #+#    #+#             */
/*   Updated: 2021/10/29 13:58:49 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_primary.h"

void	ft_new_sgm_limit(t_element *stack, t_element *limit)
{
	while (limit && stack && stack->next != limit)
		stack = stack->next;
	if (stack && limit)
		stack->chunk_limit = 1;
}

void	ft_set_sgm_limit(t_element **b, int *is_limit_set)
{
	if (*is_limit_set)
	{
		(*b)->chunk_limit = 0;
	}
	else
	{
		(*b)->chunk_limit = 1;
		*is_limit_set = 1;
	}
}

int	ft_segment_len(t_element *a)
{
	int	n_elem;

	n_elem = 0;
	while (a && !a->chunk_limit && a->n_val)
	{
		a = a->next;
		n_elem++;
	}
	if (a->n_val)
		n_elem++;
	return (n_elem);
}
