/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_srt_three.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 14:21:37 by irodrigo          #+#    #+#             */
/*   Updated: 2021/10/29 14:21:39 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_primary.h"

void	ft_srthree(t_element **a, t_element **b)
{
	t_element	*next;

	next = (*a)->next;
	if (ft_sorted(*a, 3, UP))
		return ;
	if ((*a)->n_val == 1 && !next->n_val)
		swap_a(a, b, 1);
	else if ((*a)->n_val == 2 && next->n_val)
	{
		swap_a(a, b, 1);
		rot_rev_a(a, b, 1);
	}
	else if ((*a)->n_val == 2 && !next->n_val)
		rot_a(a, b, 1);
	else if (!(*a)->n_val && next->n_val == 2)
	{
		swap_a(a, b, 1);
		rot_a(a, b, 1);
	}
	else
		rot_rev_a(a, b, 1);
}
