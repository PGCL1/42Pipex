# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/27 16:39:11 by glacroix          #+#    #+#              #
#    Updated: 2023/04/11 12:40:56 by glacroix         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
NAME_BONUS = pipex_bonus

CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEBUG = -g -fsanitize=address

LIBFT = ./42Libft/libft.a
LIB = src/pipex.h

SRC_PATH = ./src/

SRC =	main.c\
		double_free.c\
		errors.c\
		pipex.c\
		print_error.c\
		utils.c\
		ft_leaks.c

SRCS = $(addprefix $(SRC_PATH), $(SRC))

OBJS = $(SRCS:.c=.o)

all: make_libft $(NAME)

make_libft:
	@make all -C ./42Libft

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -I $(LIB) $(LIBFT) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@make clean -C ./42Libft
	@rm -rf $(OBJS_PATH)


fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./42Libft
	@rm -rf $(OBJS_PATH)

re: fclean all

re_bonus: fclean

.PHONY: all clean fclean re bonus