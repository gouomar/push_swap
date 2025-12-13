/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomar <gomar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 23:47:27 by gomar             #+#    #+#             */
/*   Updated: 2025/11/09 23:48:22 by gomar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_BONUS_H
# define LIBFTPRINTF_BONUS_H

# include "libft.h"
# include <stdarg.h>
# include <unistd.h>

typedef struct s_flags
{
	int				minus;
	int				zero;
	int				width;
	int				dot;
	int				precision;

	int				hash;
	int				space;
	int				plus;

}					t_flags;

typedef struct s_pad
{
	int				zero;
	int				space;
	struct s_flags	*flag;
}					t_pad;

int					ft_printf(const char *format, ...);
int					check_type(char index, va_list arg_po, t_flags *flags);
int					print_char(int c, t_flags *flags);
int					print_string(char *s, t_flags *flags);
int					print_pointer(void *p, t_flags *flags);
int					print_decimal(int n, t_flags *flags);
int					print_unsigned(unsigned int n, t_flags *flags);
int					print_hex_lower(unsigned int n, t_flags *flags);
int					print_hex_upper(unsigned int n, t_flags *flags);
int					print_percent(t_flags *flags);
int					ft_putchar(char c, int fd);
int					ft_print_padding(int times, char c);
int					ft_putnbr_digits(unsigned int n);
int					ft_numlen(unsigned int n);

#endif