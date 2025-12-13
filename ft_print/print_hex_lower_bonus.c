/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_lower_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomar <gomar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 18:29:06 by gomar             #+#    #+#             */
/*   Updated: 2025/11/03 20:07:23 by gomar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

static int	ft_puthex_digits_lower(unsigned int n)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789abcdef";
	if (n >= 16)
		count += ft_puthex_digits_lower(n / 16);
	count += ft_putchar(base[n % 16], 1);
	return (count);
}

static int	ft_hexlen(unsigned int n)
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

static void	handle_hex_zero_edgecase(t_flags *flags, unsigned int n, int *n_len)
{
	if (flags->dot == 1 && flags->precision == 0 && n == 0)
		*n_len = 0;
}

static t_pad	calculate_hex_padding(t_flags *flags, int n_len, int p_len)
{
	t_pad	pad;
	int		total_len;

	pad.zero = flags->precision - n_len;
	if (pad.zero < 0)
		pad.zero = 0;
	total_len = n_len + pad.zero + p_len;
	pad.space = flags->width - total_len;
	if (pad.space < 0)
		pad.space = 0;
	if (flags->zero == 1 && flags->minus == 0 && flags->dot == 0)
	{
		pad.zero += pad.space;
		pad.space = 0;
	}
	return (pad);
}

int	print_hex_lower(unsigned int n, t_flags *flags)
{
	int		count;
	int		n_len;
	int		prefix_len;
	t_pad	padding;

	count = 0;
	n_len = ft_hexlen(n);
	handle_hex_zero_edgecase(flags, n, &n_len);
	prefix_len = 0;
	if (flags->hash == 1 && n != 0)
		prefix_len = 2;
	padding = calculate_hex_padding(flags, n_len, prefix_len);
	if (flags->minus == 0)
		count += ft_print_padding(padding.space, ' ');
	if (prefix_len > 0)
		count += write(1, "0x", 2);
	count += ft_print_padding(padding.zero, '0');
	if (n_len > 0)
		count += ft_puthex_digits_lower(n);
	if (flags->minus == 1)
		count += ft_print_padding(padding.space, ' ');
	return (count);
}
