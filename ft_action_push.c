/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 11:41:32 by irodrigo          #+#    #+#             */
/*   Updated: 2021/10/29 11:58:50 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_primary.h"

void	push_a(t_element **stk_a, t_element **stk_b, int out)
{
	push(stk_b, stk_a);
	if (out)
		write (1, "pa\n", 3);
}

void	push_b(t_element **stk_a, t_element **stk_b, int out)
{
	push(stk_a, stk_b);
	if (out)
		write (1, "pb\n", 3);
}

void	push(t_element **first, t_element **last)
{
	t_element	*aux;

	if (*first)
	{
		aux = (*first)->next;
		(*first)->next = *last;
		*last = *first;
		*first = aux;
	}
}
