/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomar <gomar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 00:00:00 by gomar             #+#    #+#             */
/*   Updated: 2025/12/13 00:00:00 by gomar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	add_number_to_stack(t_stack *a, char *str)
{
	long	num;
	t_node	*node;

	if (!is_valid_number(str))
		return (0);
	num = ft_atoi(str);
	if (num > 2147483647 || num < -2147483648)
		return (0);
	if (has_duplicates(a, (int)num))
		return (0);
	node = node_new((int)num);
	if (!node)
		return (0);
	stack_push(a, node);
	return (1);
}

static int	process_arg(t_stack *a, char *arg)
{
	char	**split;
	int		j;

	split = ft_split(arg, ' ');
	if (!split)
		return (0);
	j = 0;
	while (split[j])
	{
		if (!add_number_to_stack(a, split[j]))
		{
			free_split(split);
			return (0);
		}
		j++;
	}
	free_split(split);
	return (1);
}

static void	reverse_stack(t_stack *a)
{
	t_node	*temp_stack;
	t_node	*next;
	t_node	*prev;

	temp_stack = NULL;
	while (a->top)
	{
		next = a->top->next;
		a->top->next = temp_stack;
		temp_stack = a->top;
		a->top = next;
	}
	a->top = temp_stack;
	prev = NULL;
	while (temp_stack)
	{
		temp_stack->prev = prev;
		prev = temp_stack;
		temp_stack = temp_stack->next;
	}
}

int	parse_args(int argc, char **argv, t_stack *a)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!process_arg(a, argv[i]))
			return (0);
		i++;
	}
	reverse_stack(a);
	return (1);
}
