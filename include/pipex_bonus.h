/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 19:31:45 by glacroix          #+#    #+#             */
/*   Updated: 2023/04/15 19:34:44 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H


# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include <sys/errno.h>
# include <fcntl.h>
# include <stdarg.h>
# include "../42Libft/libft.h"

# define READ_END 0
# define WRITE_END 1
# define FILE_NAME "file.txt"

typedef struct s_pipe
{
	int fd[2];
	int pipe[2];
	pid_t pid;
	int status;
}				t_pipe;


#endif