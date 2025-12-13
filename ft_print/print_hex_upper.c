/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_upper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomar <gomar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 20:06:44 by gomar             #+#    #+#             */
/*   Updated: 2025/11/02 13:57:45 by gomar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	hex(unsigned long long n)
{
	int		count;
	char	*index;

	count = 0;
	index = "0123456789ABCDEF";
	if (n >= 16)
	{
		count += hex(n / 16);
	}
	ft_putchar_fd(index[n % 16], 1);
	count++;
	return (count);
}

int	print_hex_upper(unsigned int x)
{
	return (hex(x));
}
