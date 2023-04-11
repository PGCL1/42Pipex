/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:39:18 by glacroix          #+#    #+#             */
/*   Updated: 2023/04/11 12:36:21 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

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
	int		fd[2];
	int		pipe[2];
	pid_t	pid;
	int		status;
}				t_pipe;

void	execute_cmd(char *cmd, char **envp, int *flag);
char	*find_path(char **envp, char *cmd);
void	first_child(char **argv, char **envp, t_pipe *pointer);
void	second_child(char **argv, char **envp, t_pipe *pointer);
int		main(int argc, char **argv, char **envp);
int		pipex(char **argv, char **envp);
void	print_error(char *format, ...);
void	error_log(void);
void	double_free(char **pointer);
void	artificial_bash(char *cmd, int *flag);

#endif
