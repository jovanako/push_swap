# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/31 16:24:37 by jkovacev          #+#    #+#              #
#    Updated: 2025/04/11 13:36:29 by jkovacev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

CFLAGS = -g -O0 -Wall -Wextra -Werror

SRCS = push_swap.c \
		stack.c \
		list.c \
		ft_atoi.c \
		ft_itoa.c \
		instructions_rotate.c \
		instructions_swap_push.c \
		parse_input.c \
		pre_sort.c \
		sort_five_nums.c \
		sort_three_nums.c \
		radix_sort.c \
		sort.c

OBJS = $(SRCS:.c=.o)

DEPS = list.h \
		stack.h \
		parse_input.h \
		instructions.h \
		sort.h

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re