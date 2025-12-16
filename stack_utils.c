/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomar <gomar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 00:00:00 by gomar             #+#    #+#             */
/*   Updated: 2025/12/16 13:16:04 by gomar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *stack)
{
	if (!stack)
		return (0);
	return (stack->size);
}

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->top)
		return (1);
	current = stack->top;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	stack_push(t_stack *stack, t_node *node)
{
	if (!stack || !node)
		return ;
	node->next = stack->top;
	node->prev = NULL;
	if (stack->top)
		stack->top->prev = node;
	stack->top = node;
	stack->size++;
}

t_node	*stack_pop(t_stack *stack)
{
	t_node	*node;

	if (!stack || !stack->top)
		return (NULL);
	node = stack->top;
	stack->top = node->next;
	if (stack->top)
		stack->top->prev = NULL;
	node->next = NULL;
	node->prev = NULL;
	stack->size--;
	return (node);
}
