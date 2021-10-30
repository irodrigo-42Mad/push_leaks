/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 13:25:06 by irodrigo          #+#    #+#             */
/*   Updated: 2021/10/29 13:25:22 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_primary.h"

void	swap_a(t_element **stk_a, t_element **stk_b, int out)
{
	(void)stk_b;
	swap(stk_a);
	if (out)
		write (1, "sa\n", 3);
}

void	swap_b(t_element **stk_a, t_element **stk_b, int out)
{
	(void)stk_a;
	swap(stk_b);
	if (out)
		write (1, "sb\n", 3);
}

void	swap_ab(t_element **stk_a, t_element **stk_b, int out)
{
	swap(stk_a);
	swap(stk_b);
	if (out)
		write (1, "ss\n", 3);
}

void	swap(t_element **stk)
{
	t_element	*aux;

	if (*stk)
	{
		aux = (*stk)->next;
		(*stk)->next = aux->next;
		aux->next = *stk;
		*stk = aux;
	}
}
