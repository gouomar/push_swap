/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomar <gomar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 13:52:46 by gomar             #+#    #+#             */
/*   Updated: 2025/11/02 14:01:52 by gomar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	hex(unsigned long long n)
{
	int		count;
	char	*index;

	count = 0;
	index = "0123456789abcdef";
	if (n >= 16)
	{
		count += hex(n / 16);
	}
	ft_putchar_fd(index[n % 16], 1);
	count++;
	return (count);
}

int	print_pointer(void *p)
{
	unsigned long long	i;
	int					count;

	if (!p)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	count = 2;
	i = (unsigned long long)p;
	ft_putstr_fd("0x", 1);
	count += hex(i);
	return (count);
}
