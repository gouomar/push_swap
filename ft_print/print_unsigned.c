/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomar <gomar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 17:54:13 by gomar             #+#    #+#             */
/*   Updated: 2025/11/02 14:02:22 by gomar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	count(unsigned int n)
{
	int	count;

	count = 1;
	while (n > 9)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	ft_putnbr_un(unsigned int n, int fd)
{
	if (n > 9)
		ft_putnbr_un(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
}

int	print_unsigned(unsigned int u)
{
	ft_putnbr_un(u, 1);
	return (count(u));
}
