# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gomar <gomar@student.1337.ma>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/13 00:00:00 by gomar             #+#    #+#              #
#    Updated: 2025/12/20 15:09:22 by gomar            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECKER = checker

PRINTF_DIR = ft_print
PRINTF = $(PRINTF_DIR)/libftprintf.a

SRCS = main.c \
       stack_init.c \
       stack_utils.c \
       operations_swap.c \
       operations_push.c \
       operations_rotate.c \
       operations_reverse_rotate.c \
       parsing.c \
       parsing_utils.c \
       utils.c \
       sort.c \
       sort_small.c \
       sort_utils.c

CHECKER_SRCS = checker_bonus.c \
               stack_init.c \
               stack_utils.c \
               operations_swap.c \
               operations_push.c \
               operations_rotate.c \
               operations_reverse_rotate.c \
               parsing.c \
               parsing_utils.c \
               utils.c

OBJS = $(SRCS:.c=.o)
CHECKER_OBJS = $(CHECKER_SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I. -I$(PRINTF_DIR) -I$(PRINTF_DIR)/libft
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF) -o $(NAME)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

bonus: $(CHECKER)

$(CHECKER): $(CHECKER_OBJS) $(PRINTF)
	$(CC) $(CFLAGS) $(CHECKER_OBJS) $(PRINTF) -o $(CHECKER)

clean:
	$(MAKE) -C $(PRINTF_DIR) clean
	$(RM) $(OBJS) $(CHECKER_OBJS)

fclean: clean
	$(MAKE) -C $(PRINTF_DIR) fclean
	$(RM) $(NAME) $(CHECKER)

re: fclean all

.PHONY: all clean fclean re bonus
