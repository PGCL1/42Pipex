# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/27 16:39:11 by glacroix          #+#    #+#              #
#    Updated: 2023/02/27 17:08:05 by glacroix         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex.a
HEADER = pipex.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I inc -I libft

SRC =

OBJS = $(SRCS:.c=.o)
LIB = libft/libft.a

$(NAME): $(OBJS)
	@make -C libft
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)
	@echo "everything compiled"

all: $(NAME)

clean:
	make clean -C libft
	@rm -rf $(OBJS)

fclean: clean
	make fclean -C libft
	@rm -f $(NAME)

re: fclean all

leaks:
	@echo 7768696c6520747275653b20646f206c65616b732070697065783b20736c65657020323b20646f6e653b | xxd -r -p | zsh

norma:
	@echo 6966205b5b2024286e6f726d696e65747465207c206772657020274572726f7227207c207763202d6c29202d65712030205d5d3b207468656e206e6f726d696e657474653b20656c736520286e6f726d696e65747465207c206772657020274572726f7227293b206669 | xxd -r -p | zsh

.PHONY: all clean fclean re norma