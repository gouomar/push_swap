/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomar <gomar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 23:47:27 by gomar             #+#    #+#             */
/*   Updated: 2025/11/03 18:32:12 by gomar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	check_type(char specifier, va_list args);
int	print_char(char c);
int	print_string(char *s);
int	print_pointer(void *p);
int	print_decimal(int n);
int	print_unsigned(unsigned int u);
int	print_hex_lower(unsigned int x);
int	print_hex_upper(unsigned int x);
int	print_percent(void);

#endif