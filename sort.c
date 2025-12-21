/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomar <gomar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 10:26:21 by gomar             #+#    #+#             */
/*   Updated: 2025/12/20 15:09:22 by gomar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_chunks_to_b(t_stack *a, t_stack *b)
{
	int	counter;
	int	chunk_size;

	counter = 0;
	chunk_size = get_chunk_factor(a->size);
	while (a->size > 0)
	{
		if (a->top->index <= counter)
		{
			pb(a, b, 1);
			rb(b, 1);
			counter++;
		}
		else if (a->top->index <= counter + chunk_size)
		{
			pb(a, b, 1);
			counter++;
		}
		else
			ra(a, 1);
	}
}

static void	push_back_to_a(t_stack *a, t_stack *b)
{
	int	max_pos;
	int	size;

	while (b->size > 0)
	{
		max_pos = get_max_pos(b);
		size = b->size;
		if (max_pos <= size / 2)
		{
			while (max_pos-- > 0)
				rb(b, 1);
		}
		else
		{
			while (max_pos++ < size)
				rrb(b, 1);
		}
		pa(a, b, 1);
	}
}

void	sort_large(t_stack *a, t_stack *b)
{
	push_chunks_to_b(a, b);
	push_back_to_a(a, b);
}

void	sort_stack(t_stack *a, t_stack *b)
{
	int	size;

	size = a->size;
	if (size <= 1)
		return ;
	else if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else if (size <= 5)
		sort_small(a, b);
	else
		sort_large(a, b);
}
