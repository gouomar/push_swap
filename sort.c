/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomar <gomar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 00:00:00 by gomar             #+#    #+#             */
/*   Updated: 2025/12/13 00:00:00 by gomar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Main sorting function dispatcher
** - 1 element: already sorted
** - 2 elements: simple swap if needed
** - 3 elements: hardcoded optimal solution
** - 4-5 elements: small stack optimization
** - 6+ elements: main algorithm (TO BE IMPLEMENTED)
*/
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

/*
** ============================================================================
** MAIN SORTING ALGORITHM - TO BE IMPLEMENTED
** ============================================================================
**
** This is where your main sorting algorithm goes!
**
** Popular approaches for push_swap:
**
** 1. RADIX SORT (using indices/binary representation)
**    - Simple to implement
**    - Consistent performance ~O(n * log(n)) operations
**    - Works by sorting bit by bit
**    - Typically achieves: ~100 nums in ~700 ops, ~500 nums in ~5500 ops
**
** 2. TURKISH ALGORITHM / COST-BASED SORTING
**    - Calculate cost to move each element
**    - Always pick the cheapest move
**    - Can be very efficient but more complex
**
** 3. CHUNK-BASED SORTING
**    - Divide elements into chunks
**    - Push chunks to stack B
**    - Rebuild in sorted order
**
** 4. MECHANICAL TURK / GREEDY ALGORITHM
**    - For each element in A, find best position in B
**    - Calculate rotation costs and optimize
**
** Tips:
** - Use the index field (assigned in assign_indices) instead of values
** - Indices are 0 to n-1, making algorithms easier
** - For radix: check bit at position i to decide pb or ra
**
** ============================================================================
*/
void	sort_large(t_stack *a, t_stack *b)
{
	(void)a;
	(void)b;
	/*
	** TODO: Implement your sorting algorithm here!
	**
	** Example radix sort pseudocode:
	**
	** int max_bits = calculate_max_bits(a->size);
	** for (int bit = 0; bit < max_bits; bit++)
	** {
	**     int size = a->size;
	**     for (int i = 0; i < size; i++)
	**     {
	**         if ((a->top->index >> bit) & 1)
	**             ra(a, 1);
	**         else
	**             pb(a, b, 1);
	**     }
	**     while (b->size > 0)
	**         pa(a, b, 1);
	** }
	*/
}
