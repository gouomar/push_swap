/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomar <gomar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 23:51:15 by gomar             #+#    #+#             */
/*   Updated: 2025/11/03 18:37:29 by gomar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

static void	init_flags(t_flags *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->width = 0;
	flags->dot = 0;
	flags->precision = 0;
	flags->hash = 0;
	flags->space = 0;
	flags->plus = 0;
}

static void	search_flags(const char *format, int *i, t_flags *flags)
{
	while (ft_strchr("-0# +", format[*i]))
	{
		if (format[*i] == '-')
			flags->minus = 1;
		else if (format[*i] == '0')
			flags->zero = 1;
		else if (format[*i] == '#')
			flags->hash = 1;
		else if (format[*i] == '+')
			flags->plus = 1;
		else if (format[*i] == ' ')
			flags->space = 1;
		(*i)++;
	}
}

static void	search_width_precision(const char *format, int *i, t_flags *flags)
{
	if (ft_isdigit(format[*i]))
	{
		flags->width = ft_atoi(&format[*i]);
		while (ft_isdigit(format[*i]))
			(*i)++;
	}
	if (format[*i] == '.')
	{
		flags->dot = 1;
		(*i)++;
		flags->precision = ft_atoi(&format[*i]);
		while (ft_isdigit(format[*i]))
			(*i)++;
	}
}

static int	evaluate_format(const char *format, int *i, va_list arg_po)
{
	t_flags	flags;
	int		count;

	count = 0;
	init_flags(&flags);
	search_flags(format, i, &flags);
	search_width_precision(format, i, &flags);
	if (flags.minus == 1)
		flags.zero = 0;
	if (flags.dot == 1)
		flags.zero = 0;
	if (flags.plus == 1)
		flags.space = 0;
	count += check_type(format[*i], arg_po, &flags);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg_po;
	int		i;
	int		total_count;

	if (!format)
		return (-1);
	va_start(arg_po, format);
	i = 0;
	total_count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			total_count += evaluate_format(format, &i, arg_po);
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
