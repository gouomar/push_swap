# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gomar <gomar@student.1337.ma>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/02 14:04:27 by gomar             #+#    #+#              #
#    Updated: 2025/11/09 23:38:35 by gomar            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = libft/libft.a

SRCS_MANDATORY =  ft_printf.c \
                  print_char.c \
                  print_string.c \
                  print_pointer.c \
                  print_decimal.c \
                  print_unsigned.c \
                  print_hex_lower.c \
                  print_hex_upper.c \
                  print_percent.c \
                  check_type.c \

SRCS_BONUS =  ft_printf_bonus.c \
              print_char_bonus.c \
              print_string_bonus.c \
              print_pointer_bonus.c \
              print_decimal_bonus.c \
              print_unsigned_bonus.c \
              print_hex_lower_bonus.c \
              print_hex_upper_bonus.c \
              print_percent_bonus.c \
              check_type_bonus.c \
              ft_putchar_bonus.c \
              ft_putnbr_digits_bonus.c \
              ft_numlen_bonus.c \
              ft_print_padding_bonus.c

HEADER_MANDATORY = libftprintf.h
HEADER_BONUS = libftprintf_bonus.h

OBJS_MANDATORY = $(SRCS_MANDATORY:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

CC = cc
AR = ar rcs
RM = rm -f

CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I libft

all: $(NAME)

$(NAME): $(OBJS_MANDATORY) $(LIBFT)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS_MANDATORY)

$(LIBFT):
	$(MAKE) -C libft

bonus: $(OBJS_BONUS) $(LIBFT)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS_BONUS)

%.o: %.c $(HEADER_MANDATORY)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

%_bonus.o: %_bonus.c $(HEADER_BONUS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C libft clean
	$(RM) $(OBJS_MANDATORY) $(OBJS_BONUS)

fclean:
	$(MAKE) -C libft fclean
	$(RM) $(OBJS_MANDATORY) $(OBJS_BONUS) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus