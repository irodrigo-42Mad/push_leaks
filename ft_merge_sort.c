/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 13:51:12 by irodrigo          #+#    #+#             */
/*   Updated: 2021/10/29 13:54:47 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_primary.h"

static t_element	*merge(t_element *stk_a, t_element *stk_b)
{
	int	a_len;

	a_len = ft_lstlength(stk_a);
	if (ft_strtwo(&stk_a, &stk_b))
		return (stk_a);
	while (stk_b && a_len > 0)
	{
		if (stk_a->value < stk_b->value)
			ft_stka_rm(&stk_a, &stk_b, &a_len);
		else
			ft_stkb_rm(&stk_a, &stk_b, 0);
	}
	while (a_len > 0)
		ft_stka_rm(&stk_a, &stk_b, &a_len);
	while (stk_b)
		ft_stkb_rm(&stk_a, &stk_b, 0);
	return (stk_a);
}

t_element	*merge_sort(t_element *stack_a)
{
	t_element	*stack_b;
	int			len;

	len = ft_lstlength(stack_a);
	if (len <= 1)
		return (stack_a);
	stack_b = split_stk(&stack_a, len / 2);
	stack_a = merge_sort(stack_a);
	stack_b = merge_sort(stack_b);
	return (merge(stack_a, stack_b));
}
