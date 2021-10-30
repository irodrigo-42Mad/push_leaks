/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_aux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 13:14:40 by irodrigo          #+#    #+#             */
/*   Updated: 2021/10/30 14:40:42 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_primary.h"

void	ft_first_sort(t_element **el)
{
	int			n_elm;
	int			x;
	t_element	*sorted;

	x = 0;
	n_elm = ft_lstlength(*el);
	//system ("leaks push_swap");
	sorted = ft_partial_sort(*el, ft_lstlength(*el));
	while (x < n_elm)
	{
		ft_search_replace(sorted, *el, x);
		sorted = sorted->next;
		x++;
	}
}

t_element	*ft_init_stack(char **els)
{
	t_element	*stk;

	stk = NULL;
	while (*els)
	{
		ft_addlst(&stk, ft_elm_atoi(*els));
		els++;
	}
	//ft_clean_number_table(els);
	return (stk);
}

t_element	*ft_partial_sort(t_element *first, int n_elm)
{
	t_element	*stk;

	stk = ft_stk_extract(first, n_elm);
	stk = merge_sort(stk);
	return (stk);
}

void	ft_search_replace(t_element *source, t_element *dest, int val)
{
	while (dest && source->value != dest->value)
		dest = dest->next;
	if (dest)
		dest->n_val = val;
}

t_element	*ft_stk_extract(t_element *start, int n_elm)
{
	t_element	*stk;

	stk = NULL;
	while (n_elm)
	{
		ft_addlst(&stk, start->value);
		start = start->next;
		n_elm--;
	}
	return (stk);
}
