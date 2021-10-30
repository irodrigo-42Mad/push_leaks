/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 13:48:11 by irodrigo          #+#    #+#             */
/*   Updated: 2021/10/29 13:48:16 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_primary.h"

short	ft_sorted(t_element *start, int len, short order)
{
	t_element	*next;

	while (len > 1)
	{
		next = start->next;
		if (order == UP && start->value > next->value)
			return (0);
		if (order == DOWN && start->value < next->value)
			return (0);
		start = next;
		len--;
	}
	return (1);
}

short	ft_max_min(t_element *stk)
{
	t_element	*srt;
	int			len;

	len = ft_lstlength(stk);
	srt = ft_partial_sort(stk, len);
	return ((short)(ft_lstgetlast(srt)->value == ft_lstgetlast(stk)->value)
		   || (short)(ft_lstgetlast(srt)->value == stk->value)
		   || (short)(srt->value == stk->value));
}

short	ft_has_lftval(t_element *b, t_element *axis)
{
	while (b)
	{
		if (b->value > axis->value)
			return (1);
		b = b->next;
	}
	return (0);
}
