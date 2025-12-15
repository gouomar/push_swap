/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomar <gomar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 00:00:00 by gomar             #+#    #+#             */
/*   Updated: 2025/12/15 09:43:05 by gomar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	sort_two(t_stack *a)
{
	if (a->top->value > a->top->next->value)
		sa(a, 1);
}

void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	if (!a || a->size < 2)
		return ;
	if (a->size == 2)
		return (sort_two(a));
	first = a->top->value;
	second = a->top->next->value;
	third = a->top->next->next->value;
	if (first > second && first > third)
		ra(a, 1);
	else if (second > first && second > third)
		rra(a, 1);
	if (a->top->value > a->top->next->value)
		sa(a, 1);
}


static int	get_min_index_position(t_stack *stack)
{
	t_node	*current;
	int		min_index;
	int		min_pos;
	int		pos;

	current = stack->top;
	min_index = current->index;
	min_pos = 0;
	pos = 0;
	while (current)
	{
		if (current->index < min_index)
		{
			min_index = current->index;
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
