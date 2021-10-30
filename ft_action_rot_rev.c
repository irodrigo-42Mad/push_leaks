/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_rot_rev.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 13:24:50 by irodrigo          #+#    #+#             */
/*   Updated: 2021/10/29 13:24:52 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_primary.h"

void	rot_rev_a(t_element **stk_a, t_element **stk_b, int out)
{
	(void)stk_b;
	rot_rev(stk_a);
	if (out)
		write (1, "rra\n", 4);
}

void	rot_rev_b(t_element **stk_a, t_element **stk_b, int out)
{
	(void)stk_a;
	rot_rev(stk_b);
	if (out)
		write (1, "rrb\n", 4);
}

void	rot_rev_ab(t_element **stk_a, t_element **stk_b, int out)
{
	rot_rev(stk_a);
	rot_rev(stk_b);
	if (out)
		write (1, "rrr\n", 4);
}

void	rot_rev(t_element **stk)
{
	t_element	*last;
	t_element	*aux;

	if (*stk)
	{
		last = ft_lstgetlast(*stk);
		aux = lst_goto(*stk, ft_lstlength(*stk) - 2);
		last->next = *stk;
		*stk = last;
		aux->next = NULL;
	}
}
