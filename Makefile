# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/26 11:38:46 by thantoni          #+#    #+#              #
#    Updated: 2025/11/26 11:45:09 by thantoni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS =	ft_atoi.c						\
		ft_isnb.c						\
		ft_putstr.c						\
		ft_split.c						\
		ft_splitlen.c					\
		ft_strlen.c						\
		ft_strtoelems.c					\
		handler_args_initialization.c	\
		handler_sorting.c				\
		main.c							\
		operation_p.c					\
		operation_r.c					\
		t_elem__utils.c					\
		t_stack__utils.c				

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re