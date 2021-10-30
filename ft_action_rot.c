/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_rot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 13:24:58 by irodrigo          #+#    #+#             */
/*   Updated: 2021/10/29 13:24:59 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_primary.h"

void	rot(t_element **stk)
{
	t_element	*last;
	t_element	*second;

	if (*stk && (*stk)->next)
	{
		second = (*stk)->next;
		last = ft_lstgetlast(*stk);
		last->next = *stk;
		(*stk)->next = NULL;
		*stk = second;
	}
}

void	rot_a(t_element **stk_a, t_element **stk_b, int out)
{
	(void)stk_b;
	rot(stk_a);
	if (out)
		write (1, "ra\n", 3);
}

void	rot_b(t_element **stk_a, t_element **stk_b, int out)
{
	(void)stk_a;
	rot(stk_b);
	if (out)
		write (1, "rb\n", 3);
}

void	rot_ab(t_element **stk_a, t_element **stk_b, int out)
{
	rot(stk_a);
	rot(stk_b);
	if (out)
		write (1, "rr\n", 3);
}
