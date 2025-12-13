/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomar <gomar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 00:00:00 by gomar             #+#    #+#             */
/*   Updated: 2025/12/13 00:00:00 by gomar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b, int print)
{
	t_node	*node;

	if (!b || b->size == 0)
		return ;
	node = stack_pop(b);
	stack_push(a, node);
	if (print)
		ft_printf("pa\n");
}

void	pb(t_stack *a, t_stack *b, int print)
{
	t_node	*node;

	if (!a || a->size == 0)
		return ;
	node = stack_pop(a);
	stack_push(b, node);
	if (print)
		ft_printf("pb\n");
}
