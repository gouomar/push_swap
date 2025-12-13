/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomar <gomar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 20:27:28 by gomar             #+#    #+#             */
/*   Updated: 2025/11/03 20:17:51 by gomar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

int	print_percent(t_flags *flags)
{
	int		count;
	int		padding;
	char	pad_char;

	count = 0;
	padding = flags->width - 1;
	if (padding < 0)
		padding = 0;
	pad_char = ' ';
	if (flags->zero == 1)
		pad_char = '0';
	if (flags->minus == 1)
	{
		count += ft_putchar('%', 1);
		count += ft_print_padding(padding, ' ');
	}
	else
	{
		count += ft_print_padding(padding, pad_char);
		count += ft_putchar('%', 1);
	}
	return (count);
}
