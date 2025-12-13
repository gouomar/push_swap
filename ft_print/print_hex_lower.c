/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_lower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomar <gomar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 18:29:06 by gomar             #+#    #+#             */
/*   Updated: 2025/11/02 13:58:21 by gomar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	hex(unsigned long long n)
{
	int		count;
	char	*index;

	index = "0123456789abcdef";
	count = 0;
	if (n >= 16)
	{
		count += hex(n / 16);
	}
	ft_putchar_fd(index[n % 16], 1);
	count++;
	return (count);
}

int	print_hex_lower(unsigned int x)
{
	return (hex(x));
}
