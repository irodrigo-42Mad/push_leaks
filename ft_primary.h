/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_primary.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 13:35:37 by irodrigo          #+#    #+#             */
/*   Updated: 2021/10/30 13:16:50 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRIMARY_H
# define FT_PRIMARY_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <string.h>
# include "libft/libft.h"

typedef struct s_element {
	int					value;
	int					n_val;
	short				chunk_limit;
	struct s_element	*next;
}			t_element;

# define FALSE			0
# define TRUE			1

# define UP 			1
# define DOWN 			2

# define BUFFER_SIZE	1
# define FILE_DSC		4096
# define L_EOF 			'\n'

/*
** SEGMENT calc functions
*/
void		ft_new_sgm_limit(t_element *stack, t_element *limit);
void		ft_set_sgm_limit(t_element **b, int *is_limit_set);
int			ft_segment_len(t_element *a);

/*
** PUSH SWAP primary sorting functions
*/
t_element	*merge_sort(t_element *stack_a);
void		ft_first_sort(t_element **el);
void		ft_push_swap_tiny(t_element **a, t_element **b, int len);
void		ft_push_swap_norm(t_element **a, t_element **b, int len);
short		ft_strtwo(t_element **a, t_element **b);
void		ft_srthree(t_element **a, t_element **b);

/*
** STACK movement functions
*/
void		ft_stka_rm(t_element **a, t_element **b, int *a_len);
void		ft_stkb_rm(t_element **a, t_element **b, int out);
void		ft_split_stka(t_element **a, t_element **b, int n_elm);
void		ft_split_stkb(t_element **a, t_element **b, int n_elm);
void		ft_setcntnt_back(t_element **a, t_element **b, int n_elm);
void		ft_bk_split(t_element **a, t_element **b, int n_elm);
void		ft_small_splb(t_element **a, t_element **b, int len);
void		ft_rot_maxs(t_element **a, t_element **b);
void		ft_stack_bkrt(t_element **a, t_element **b, int n_elm);
void		ft_splitrot_stkb(t_element **a, t_element **b, int n_elm);
t_element	*split_stk(t_element **stk, int n_elm);

/*
** STACKS permited actions and operations
*/
void		swap(t_element **stk);
void		swap_a(t_element **stk_a, t_element **stk_b, int out);
void		swap_b(t_element **stk_a, t_element **stk_b, int out);
void		swap_ab(t_element **stk_a, t_element **stk_b, int out);
void		rot(t_element **stk);
void		rot_a(t_element **stk_a, t_element **stk_b, int out);
void		rot_b(t_element **stk_a, t_element **stk_b, int out);
void		rot_ab(t_element **stk_a, t_element **stk_b, int out);
void		rot_rev(t_element **stk);
void		rot_rev_a(t_element **stk_a, t_element **stk_b, int out);
void		rot_rev_b(t_element **stk_a, t_element **stk_b, int out);
void		rot_rev_ab(t_element **stk_a, t_element **stk_b, int out);
void		push(t_element **first, t_element **last);
void		push_a(t_element **stk_a, t_element **stk_b, int out);
void		push_b(t_element **stk_a, t_element **stk_b, int out);

/*
** STACKS auxiliary data operations
*/
t_element	*ft_init_stack(char **els);
t_element	*ft_partial_sort(t_element *start, int len);
t_element	*ft_stk_extract(t_element *start, int len);

/*
** GENERAL list utils
*/
void		ft_addlst(t_element **stk, int val);
int			ft_lstlength(t_element *stk);
t_element	*ft_lstgetlast(t_element *stk);
t_element	*lst_goto(t_element *stk, short pos);

/*
** ERROR control application functions
*/
void		ft_error(void);

/*
** UTILS Auxiliary functions
*/
void		ft_clean_number_table(char **str);
void		ft_set_string(char *s[4096], char *buffer, int fd, char *aux);
void		ft_search_replace(t_element *source, t_element *dest, int val);
int			ft_elm_atoi(char *nptr);
short		ft_sorted(t_element *first, int n_el, short order);
short		ft_max_min(t_element *stk);
short		ft_has_lftval(t_element *b, t_element *axis);
char		*ft_parse_argv(int argc, char **argv);

#endif
