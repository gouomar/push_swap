/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomar <gomar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 00:00:00 by gomar             #+#    #+#             */
/*   Updated: 2025/12/13 00:00:00 by gomar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(t_stack *a, t_stack *b)
{
	if (a)
		stack_clear(&a);
	if (b)
		stack_clear(&b);
	write(2, "Error\n", 6);
	exit(1);
}

static t_node	*get_min_node(t_stack *stack)
{
	t_node	*current;
	t_node	*min;

	if (!stack || !stack->top)
		return (NULL);
	current = stack->top;
	min = current;
	while (current)
	{
		if (current->index == -1 && current->value < min->value)
			min = current;
		else if (min->index != -1 && current->index == -1)
			min = current;
		current = current->next;
	}
	return (min);
}

void	assign_indices(t_stack *stack)
{
	int		index;
	t_node	*min;

	if (!stack || !stack->top)
		return ;
	index = 0;
	while (index < stack->size)
	{
		min = get_min_node(stack);
		if (min)
			min->index = index;
		index++;
	}
}
