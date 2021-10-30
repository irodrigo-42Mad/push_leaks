/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_com_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 14:27:00 by irodrigo          #+#    #+#             */
/*   Updated: 2021/10/30 13:49:58 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_primary.h"

static void	iterate(char *nptr, long *num)
{
	while (*nptr)
	{
		if (!ft_isdigit(*nptr))
			ft_error();
		*num = (*num) * 10 + *nptr - '0';
		nptr++;
	}
}

void	ft_clean_number_table(char **str)
{
	int i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	ft_elm_atoi(char *nptr)
{
	long	num;
	short	sign;

	num = 0;
	sign = 1;
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	iterate(nptr, &num);
	if ((sign * num) > INT_MAX || (sign * num) < INT_MIN)
		ft_error();
	return ((int)(sign * num));
}

char	*ft_parse_argv(int argc, char **argv)
{
	int		i;
	char	*aux;
	char	*data;

	i = 2;
	data = strdup(argv[1]);
	while (i < argc)
	{
		aux = data;
		data = ft_strjoin(aux, " ");
		free(aux);
		aux = data;
		data = ft_strjoin(aux, argv[i]);
		free(aux);
		i++;
	}
	return (data);
}
