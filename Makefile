# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/27 16:39:11 by glacroix          #+#    #+#              #
#    Updated: 2023/04/15 19:35:48 by glacroix         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Programs
# **************************************************************************** #
PROG			= pipex
PROG_B			= pipex_bonus

#Execution
# **************************************************************************** #
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
DEBUG			= -g -fsanitize=address
INCLUDES		= -Iinclude

#SRC Details
# **************************************************************************** #
SRCS_PATH       = ./src/
SRCS            = $(addprefix $(SRCS_PATH), $(SRC))
SRC				= main.c\
					commands.c\
				    errors.c\
				    memory.c\
				    pipex.c\
				    utils.c\
				    path.c
OBJS            =   $(SRCS:%.c=%.o)

#Bonus SRC Details
# **************************************************************************** #
#BONUS_SRCS_PATH	= ./src_bonus
#BONUS_SRCS		= $(addprefix $(BONUS_SRCS_PATH), $(BONUS_SRCS))
#BONUS_SRC		= 
#BONUS_OBJS		= $(BONUS_SRCS:.c=.o)

#SRC & BONUS SRC Executions
# **************************************************************************** #
${PROG}: ${OBJS}
	@echo "\033[33m----Compiling lib----"
	@make re -C ./42Libft
	@$(CC) $(CFLAGS) ${OBJS} $(INCLUDES) -L./42Libft -lft -o ${PROG}
	@echo "\n\033[32mPipex Compiled! 	"
	@echo "\033[32mLibft Compiled! ᕦ(\033[31m♥\033[32m_\033[31m♥\033[32m)ᕤ\n"


#${PROG_B}: ${OBJS_B}
#	@echo "\033[33m----Compiling lib----"
#	@make re -C ./42Libft
#	@$(CC) $(CFLAGS) ${OBJS_B} $(INCLUDES) -L./42Libft -lft -o ${PROG_B}
#	@echo "\033[32m Bonus Compiled! ᕦ(\033[31m♥\033[32m_\033[31m♥\033[32m)ᕤ\n"

#Makefile Commands
# **************************************************************************** #
all: ${PROG}

#bonus: ${PROG_B}

clean:
	@make clean -C ./42Libft
	@rm -f ${OBJS} ${OBJS_B}

fclean: clean
	@make fclean -C ./42Libft
	@rm -f $(NAME)
	@rm -f ${PROG} $(PROG_B)
	@echo "\n\033[31mDeleting EVERYTHING! ⌐(ಠ۾ಠ)¬\n"

re: fclean all

re_bonus: fclean bonus

.PHONY: all clean fclean re re_bonus bonus