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

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	has_duplicates(t_stack *stack, int value)
{
	t_node	*current;

	if (!stack || !stack->top)
		return (0);
	current = stack->top;
	while (current)
	{
		if (current->value == value)
			return (1);
		current = current->next;
	}
	return (0);
}

static long	ft_atol(const char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

static int	add_number_to_stack(t_stack *a, char *str)
{
	long	num;
	t_node	*node;

	if (!is_valid_number(str))
		return (0);
	num = ft_atol(str);
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	if (has_duplicates(a, (int)num))
		return (0);
	node = node_new((int)num);
	if (!node)
		return (0);
	stack_push(a, node);
	return (1);
}

int	parse_args(int argc, char **argv, t_stack *a)
{
	int		i;
	t_node	*temp_stack;
	t_node	*next;
	t_node	*prev;

	temp_stack = NULL;
	i = 1;
	while (i < argc)
	{
		if (!add_number_to_stack(a, argv[i]))
			return (0);
		i++;
	}
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
	return (1);
}
