/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomar <gomar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 13:52:46 by gomar             #+#    #+#             */
/*   Updated: 2025/11/03 20:29:46 by gomar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

static int	ft_puthex_digits_ull(unsigned long long n)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789abcdef";
	if (n >= 16)
		count += ft_puthex_digits_ull(n / 16);
	count += ft_putchar(base[n % 16], 1);
	return (count);
}

static int	ft_hexlen_ull(unsigned long long n)
{
	int	len;

	len = 1;
	while (n > 15)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static int	print_nil_padded(t_flags *flags)
{
	int	count;
	int	padding;

	count = 0;
	padding = flags->width - 5;
	if (padding < 0)
		padding = 0;
	if (flags->minus == 1)
	{
		count += write(1, "(nil)", 5);
		count += ft_print_padding(padding, ' ');
	}
	else
	{
		count += ft_print_padding(padding, ' ');
		count += write(1, "(nil)", 5);
	}
	return (count);
}

int	print_pointer(void *p, t_flags *flags)
{
	int					count;
	int					n_len;
	int					padding;
	unsigned long long	num;

	if (p == NULL)
		return (print_nil_padded(flags));
	count = 0;
	num = (unsigned long long)p;
	n_len = ft_hexlen_ull(num);
	padding = flags->width - (n_len + 2);
	if (padding < 0)
		padding = 0;
	if (flags->minus == 0)
		count += ft_print_padding(padding, ' ');
	count += write(1, "0x", 2);
	count += ft_puthex_digits_ull(num);
	if (flags->minus == 1)
		count += ft_print_padding(padding, ' ');
	return (count);
}
