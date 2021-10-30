/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 13:15:41 by irodrigo          #+#    #+#             */
/*   Updated: 2021/10/30 14:43:35 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_primary.h"

/*
** TODO amos lo que nos falta
**
** controlar que el parametro no se encuentre vacio
** revisar el leak de memoria principal
*/


static void	ft_clean_list(t_element *stk)
{
	t_element *tmp;

	tmp = stk;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		free (stk);
		stk = tmp;
	}
}

static void	ft_clean_all(t_element *a, t_element *b)
{
	ft_clean_list(a);
	ft_clean_list(b);
	a = NULL;
	b = NULL;
}

int	main(int argc, char **argv)
{
	t_element	*a;
	t_element	*b;
	char		*lista;
	char		**numeros;
	int			n_elm;

	if (argc < 2)
		exit(0);
	b = NULL;	
	a = NULL;
	lista = ft_parse_argv(argc, argv);
	numeros = ft_split(lista, ' ');
	free(lista);
	a = ft_init_stack(&numeros[0]);
	ft_clean_number_table(numeros);
	ft_first_sort(&a);
	n_elm = ft_lstlength(a);
	if (!ft_sorted(a, n_elm, UP))
	{
		if (n_elm <= 5)
			ft_push_swap_tiny(&a, &b, n_elm);
		else
			ft_push_swap_norm(&a, &b, n_elm);
	}
	ft_clean_all(a,b);
	system("leaks push_swap");
	return (0);
}

void	ft_error(void)
{
	write (2, "Error\n", 7);
	exit(127);
}
