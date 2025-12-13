/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomar <gomar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 17:18:32 by gomar             #+#    #+#             */
/*   Updated: 2025/11/03 20:32:02 by gomar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

static void	handle_zero_edgecase(t_flags *flags, unsigned int n, int *n_len)
{
	if (flags->dot == 1 && flags->precision == 0 && n == 0)
		*n_len = 0;
}

static unsigned int	handle_sign(int n, t_flags *flags, char *prefix)
{
	unsigned int	num;

	if (n < 0)
	{
		*prefix = '-';
		num = (unsigned int)-n;
	}
	else
	{
		num = (unsigned int)n;
		if (flags->plus == 1)
			*prefix = '+';
		else if (flags->space == 1)
			*prefix = ' ';
	}
	return (num);
}

static t_pad	calculate_padding(t_flags *flags, int n_len, int prefix_len)
{
	t_pad	pad;
	int		total_len;

	pad.zero = flags->precision - n_len;
	if (pad.zero < 0)
		pad.zero = 0;
	total_len = n_len + pad.zero + prefix_len;
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

int	print_decimal(int n, t_flags *flags)
{
	unsigned int	num;
	char			prefix;
	int				n_len;
	t_pad			padding;
	int				count;

	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	prefix = 0;
	num = handle_sign(n, flags, &prefix);
	n_len = ft_numlen(num);
	handle_zero_edgecase(flags, num, &n_len);
	padding = calculate_padding(flags, n_len, (prefix != 0));
	count = 0;
	if (flags->minus == 0)
		count += ft_print_padding(padding.space, ' ');
	if (prefix != 0)
		count += ft_putchar(prefix, 1);
	count += ft_print_padding(padding.zero, '0');
	if (n_len > 0)
		count += ft_putnbr_digits(num);
	if (flags->minus == 1)
		count += ft_print_padding(padding.space, ' ');
	return (count);
}
