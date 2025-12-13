/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomar <gomar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 00:00:00 by gomar             #+#    #+#             */
/*   Updated: 2025/12/13 00:00:00 by gomar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Sort 2 elements - just swap if needed
*/
void	sort_two(t_stack *a)
{
	if (a->top->value > a->top->next->value)
		sa(a, 1);
}

/*
** Sort 3 elements - hardcoded solution (max 2 operations)
** There are only 6 possible permutations
*/
void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	if (!a || a->size < 2)
		return ;
	if (a->size == 2)
	{
		sort_two(a);
		return ;
	}
	first = a->top->value;
	second = a->top->next->value;
	third = a->top->next->next->value;
	if (first > second && second < third && first < third)
		sa(a, 1);
	else if (first > second && second > third)
	{
		sa(a, 1);
		rra(a, 1);
	}
	else if (first > second && second < third && first > third)
		ra(a, 1);
	else if (first < second && second > third && first < third)
	{
		sa(a, 1);
		ra(a, 1);
	}
	else if (first < second && second > third && first > third)
		rra(a, 1);
}

/*
** Sort small stacks (4-5 elements)
** Strategy: push smallest to B, sort remaining with sort_three, push back
*/
static int	get_min_index_position(t_stack *stack)
{
	t_node	*current;
	int		min_val;
	int		min_pos;
	int		pos;

	current = stack->top;
	min_val = current->value;
	min_pos = 0;
	pos = 0;
	while (current)
	{
		if (current->value < min_val)
		{
			min_val = current->value;
			min_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (min_pos);
}

static void	push_min_to_b(t_stack *a, t_stack *b)
{
	int	pos;
	int	size;

	pos = get_min_index_position(a);
	size = a->size;
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ra(a, 1);
	}
	else
	{
		while (pos++ < size)
			rra(a, 1);
	}
	pb(a, b, 1);
}

void	sort_small(t_stack *a, t_stack *b)
{
	while (a->size > 3)
		push_min_to_b(a, b);
	sort_three(a);
	while (b->size > 0)
		pa(a, b, 1);
}
