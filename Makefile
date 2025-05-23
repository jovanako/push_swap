# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/31 16:24:37 by jkovacev          #+#    #+#              #
#    Updated: 2025/05/23 11:51:16 by jkovacev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c \
		stack.c \
		list.c \
		ft_atol.c \
		instructions_rotate.c \
		instructions_swap_push.c \
		ft_split.c \
		parse_input_helpers.c \
		parse_input.c \
		pre_sort.c \
		sort_five_nums.c \
		sort_three_nums.c \
		radix_sort.c \
		sort.c \
		exit_functions.c

OBJDIR = objects
OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)

DEPS = list.h \
		stack.h \
		parse_input.h \
		instructions.h \
		sort.h

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: %.c $(DEPS)
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re