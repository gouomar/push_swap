/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomar <gomar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 17:18:32 by gomar             #+#    #+#             */
/*   Updated: 2025/11/02 14:02:08 by gomar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	count(int n)
{
	int	count;
	int	is_negative;

	if (n == -2147483648)
		return (11);
	is_negative = 0;
	count = 1;
	if (n < 0)
	{
		is_negative = 1;
		n *= -1;
	}
	while (n > 9)
	{
		n /= 10;
		count++;
	}
	return (count + is_negative);
}

int	print_decimal(int n)
{
	ft_putnbr_fd(n, 1);
	return (count(n));
}
