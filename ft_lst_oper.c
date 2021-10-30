/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_oper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 13:43:59 by irodrigo          #+#    #+#             */
/*   Updated: 2021/10/29 13:44:11 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_primary.h"

static void	check_el_duplicate(t_element *stack, int value)
{
	if (stack)
	{
		while (stack->next)
		{
			if (value == stack->value)
				ft_error();
			stack = stack->next;
		}
		if (value == stack->value)
			ft_error();
	}
}

t_element	*lst_goto(t_element *stack, short pos)
{
	if (!stack)
		return (0);
	while (pos > 0)
	{
		stack = stack->next;
		pos--;
	}
	return (stack);
}

t_element	*ft_lstgetlast(t_element *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
	{
		stack = stack->next;
	}
	return (stack);
}

void	ft_addlst(t_element **stk, int val)
{
	t_element	*new;
	t_element	*last;

	if (stk)
	{
		new = malloc(sizeof(t_element));
		if (new)
		{
			check_el_duplicate(*stk, val);
			new->value = val;
			new->chunk_limit = 0;
			new->next = NULL;
			if (!*stk)
				*stk = new;
			else
			{
				last = ft_lstgetlast(*stk);
				last->next = new;
			}
		}
	}
}

int	ft_lstlength(t_element *stk)
{
	int	n_elm;

	n_elm = 0;
	if (!stk)
		return (0);
	while (stk->next)
	{
		stk = stk->next;
		n_elm++;
	}
	n_elm++;
	return (n_elm);
}
