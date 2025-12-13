/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomar <gomar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 17:54:13 by gomar             #+#    #+#             */
/*   Updated: 2025/11/03 20:17:01 by gomar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

static void	handle_zero_edgecase(t_flags *flags, unsigned int n, int *n_len)
{
	if (flags->dot == 1 && flags->precision == 0 && n == 0)
		*n_len = 0;
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

int	print_unsigned(unsigned int n, t_flags *flags)
{
	int		count;
	int		n_len;
	t_pad	padding;

	count = 0;
	n_len = ft_numlen(n);
	handle_zero_edgecase(flags, n, &n_len);
	padding = calculate_padding(flags, n_len, 0);
	if (flags->minus == 0)
		count += ft_print_padding(padding.space, ' ');
	count += ft_print_padding(padding.zero, '0');
	if (n_len > 0)
		count += ft_putnbr_digits(n);
	if (flags->minus == 1)
		count += ft_print_padding(padding.space, ' ');
	return (count);
}
