/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomar <gomar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 01:30:43 by gomar             #+#    #+#             */
/*   Updated: 2025/11/02 13:08:46 by gomar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	check_type(char index, va_list arg_po)
{
	int	count;

	count = 0;
	if (index == 'c')
		count += print_char(va_arg(arg_po, int));
	else if (index == 's')
		count += print_string(va_arg(arg_po, char *));
	else if (index == 'p')
		count += print_pointer(va_arg(arg_po, void *));
	else if (index == 'd' || index == 'i')
		count += print_decimal(va_arg(arg_po, int));
	else if (index == 'u')
		count += print_unsigned(va_arg(arg_po, unsigned int));
	else if (index == 'x')
		count += print_hex_lower(va_arg(arg_po, unsigned int));
	else if (index == 'X')
		count += print_hex_upper(va_arg(arg_po, unsigned int));
	else if (index == '%')
		count += print_percent();
	return (count);
}
