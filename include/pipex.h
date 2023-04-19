/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:39:18 by glacroix          #+#    #+#             */
/*   Updated: 2023/04/19 19:00:48 by glacroix         ###   ########.fr       */
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

int		cmd_check(char *cmd);
char	**cmd_find(char *cmd);
char	*cmd_find_args0(char *cmd);
void	free_pointer2pointer(char **pointer);
void	error_log(void);
void	error_print(char *format, ...);
void	cmd_error_check(char *cmd, char **envp, int flag);
void	cmd_execution(char *cmd, char **envp);
void	first_child(char **argv, char **envp, t_pipe *pointer);
int		main(int argc, char **argv, char **envp);
char	**path_find_possible(char **envp);
char	*path_found(char **envp, char *cmd);
char	*path_or_command(char *cmd, char **envp, char **args);
int		pipex(char **argv, char **envp);
void	second_child(char **argv, char **envp, t_pipe *pointer);

#endif
