# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mromao-s <mromao-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/27 20:31:57 by mromao-s          #+#    #+#              #
#    Updated: 2025/11/24 21:34:03 by mromao-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
RM = rm -f

SRCS = ft_printf.c utils/utils.c

OBJS=$(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

run:
	@$(CC) $(CFLAGS) $(NAME) -o main
	@./main

clean:
	$(RM) $(OBJS) 

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
