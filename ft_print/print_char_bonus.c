/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomar <gomar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 13:29:00 by gomar             #+#    #+#             */
/*   Updated: 2025/11/09 23:41:49 by gomar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

int	print_char(int c, t_flags *flags)
{
	int	count;
	int	padding;

	count = 0;
	padding = flags->width - 1;
	if (padding < 0)
		padding = 0;
	if (flags->minus == 1)
	{
		count += ft_putchar((char)c, 1);
		count += ft_print_padding(padding, ' ');
	}
	else
	{
		count += ft_print_padding(padding, ' ');
		count += ft_putchar((char)c, 1);
	}
	return (count);
}
