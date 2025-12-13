/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomar <gomar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 00:00:00 by gomar             #+#    #+#             */
/*   Updated: 2025/12/13 00:00:00 by gomar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_print/libftprintf.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

/*
** Stack node structure - doubly linked list
*/
typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

/*
** Stack structure
*/
typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

/*
** Initialization and cleanup
*/
t_stack		*stack_init(void);
void		stack_clear(t_stack **stack);
t_node		*node_new(int value);

/*
** Stack utilities
*/
int			stack_size(t_stack *stack);
int			is_sorted(t_stack *stack);
void		stack_push(t_stack *stack, t_node *node);
t_node		*stack_pop(t_stack *stack);

/*
** Swap operations
*/
void		sa(t_stack *a, int print);
void		sb(t_stack *b, int print);
void		ss(t_stack *a, t_stack *b, int print);

/*
** Push operations
*/
void		pa(t_stack *a, t_stack *b, int print);
void		pb(t_stack *a, t_stack *b, int print);

/*
** Rotate operations
*/
void		ra(t_stack *a, int print);
void		rb(t_stack *b, int print);
void		rr(t_stack *a, t_stack *b, int print);

/*
** Reverse rotate operations
*/
void		rra(t_stack *a, int print);
void		rrb(t_stack *b, int print);
void		rrr(t_stack *a, t_stack *b, int print);

/*
** Parsing and validation
*/
int			parse_args(int argc, char **argv, t_stack *a);
int			is_valid_number(char *str);
int			has_duplicates(t_stack *stack, int value);
void		error_exit(t_stack *a, t_stack *b);

/*
** Sorting algorithms
*/
void		sort_stack(t_stack *a, t_stack *b);
void		sort_two(t_stack *a);
void		sort_three(t_stack *a);
void		sort_small(t_stack *a, t_stack *b);

/*
** Index assignment (for radix or other algorithms)
*/
void		assign_indices(t_stack *stack);

/*
** Algorithm placeholder - TO BE IMPLEMENTED
*/
void		sort_large(t_stack *a, t_stack *b);

#endif
