# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/27 16:39:11 by glacroix          #+#    #+#              #
#    Updated: 2023/03/21 18:15:56 by glacroix         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= pipex
HEADER= pipex.h

CODEDIRS= . 42Libft_pipex 42Get_next_line
INCDIRS= . ./42Libft_pipex/ ./42Get_next_line/

CC= gcc
OPT= -O0

# automatically add the -I onto each included directories
CFLAGS= -Wall -Wextra -Werror -g3 $(foreach D,$(INCDIRS),-I$(D)) $(OPT) $(DEPFLAGS)

# finds all the .c files in all the directories that we have in the project
CFILES= $(foreach D, $(CODEDIRS), $(wildcard $(D)/*.c))

# converts all the .c files into .o (object files)
OBJS= $(patsubst %.c,%.o,$(CFILES));


all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) -o $@ $^
	@echo "\n\033[32mPipex Compiled! ᕦ(\033[31m♥\033[32m_\033[31m♥\033[32m)ᕤ\n"

%.o:%.c
	@$(CC) $(CFLAGS) -c -o $@ $^

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -f $(NAME)
	@echo "\n\033[31mCleaning Up Directories! ⌐(ಠ۾ಠ)¬\n"

re: fclean all

leaks:
	@echo 7768696c6520747275653b20646f206c65616b732070697065783b20736c65657020323b20646f6e653b | xxd -r -p | zsh

norm:
	@echo 6966205b5b2024286e6f726d696e65747465207c206772657020274572726f7227207c207763202d6c29202d65712030205d5d3b207468656e206e6f726d696e657474653b20656c736520286e6f726d696e65747465207c206772657020274572726f7227293b206669 | xxd -r -p | zsh

.PHONY: all clean fclean re norm leaks