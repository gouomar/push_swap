/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomar <gomar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 00:00:00 by gomar             #+#    #+#             */
/*   Updated: 2025/12/20 15:09:22 by gomar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_chunk_factor(int size)
{
	if (size <= 100)
		return (16);
	return (34);
}

int	get_max_pos(t_stack *b)
{
	t_node	*current;
	int		max_idx;
	int		max_pos;
	int		pos;

	current = b->top;
	max_idx = -1;
	max_pos = 0;
	pos = 0;
	while (current)
	{
		if (current->index > max_idx)
		{
			max_idx = current->index;
			max_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (max_pos);
}
