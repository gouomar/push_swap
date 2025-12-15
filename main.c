/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomar <gomar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 00:00:00 by gomar             #+#    #+#             */
/*   Updated: 2025/12/15 08:45:48 by gomar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = stack_init();
	b = stack_init(); 
	if (!a || !b)
	{
		error_exit(a, b);
		return (1);
	}
	if (!parse_args(argc, argv, a))
		error_exit(a, b);
	if (!is_sorted(a))
	{
		assign_indices(a);
		sort_stack(a, b);
	}
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}
