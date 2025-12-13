/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomar <gomar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 13:33:19 by gomar             #+#    #+#             */
/*   Updated: 2025/11/03 20:15:34 by gomar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

static char	*check_null(char *s)
{
	if (!s)
		return ("(null)");
	return (s);
}

int	print_string(char *s, t_flags *flags)
{
	int	count;
	int	len;
	int	padding;

	count = 0;
	s = check_null(s);
	len = ft_strlen(s);
	if (flags->dot == 1 && flags->precision < len)
		len = flags->precision;
	padding = flags->width - len;
	if (padding < 0)
		padding = 0;
	if (flags->minus == 1)
	{
		count += write(1, s, len);
		count += ft_print_padding(padding, ' ');
	}
	else
	{
		count += ft_print_padding(padding, ' ');
		count += write(1, s, len);
	}
	return (count);
}
