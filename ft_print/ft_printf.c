/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomar <gomar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 23:51:15 by gomar             #+#    #+#             */
/*   Updated: 2025/11/02 13:08:42 by gomar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *format, ...)
{
	va_list	arg_po;
	int		i;
	int		total_count;

	if (!format)
		return (0);
	va_start(arg_po, format);
	i = 0;
	total_count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			total_count += check_type(format[i], arg_po);
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			total_count++;
		}
		i++;
	}
	va_end(arg_po);
	return (total_count);
}
