/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:07:55 by glacroix          #+#    #+#             */
/*   Updated: 2023/04/06 16:15:51 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include <sys/errno.h>
# include <fcntl.h>
# include <stdarg.h>
# include "../42Libft/libft.h"
# include "../42GNL/get_next_line_bonus.h"

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

void check_setup_first(char **argv, char **envp, t_pipe *pointer)
{
	pointer->fd[0] = open(argv[1], O_RDWR, 0644);
	if (pointer->fd[0] < 0)
	{
		print_error("pipex: %s: %s\n", argv[1], strerror(2));
		exit(EXIT_FAILURE);
	}
	dup2(pointer->fd[0], STDIN_FILENO);
	close(pointer->pipe[READ_END]);
	dup2(pointer->pipe[WRITE_END], STDOUT_FILENO);
	close(pointer->pipe[WRITE_END]);
	//execute_cmd();
}

void check_final_setup(int argc, char **argv, char **envp, t_pipe *pointer)
{
	int	flag;

	flag = 1;
	pointer->fd[1] = open(argv[argc - 1], O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (pointer->fd[1] < 0)
		error_log();
	if (access(argv[argc - 1], R_OK | W_OK) == -1)
		print_error("pipex: %s: %s", argv[argc - 1], strerror(13));
	dup2(pointer->pipe[READ_END], STDIN_FILENO);
	close(pointer->pipe[READ_END]);
	dup2(pointer->fd[1], STDOUT_FILENO);
	//execute_cmd(argv[3], envp, &flag);
}

void	pipe_in(char **argv, char **envp, t_pipe *pointer, int i)
{
	close(pointer->pipe[READ_END]);
	close(pointer->fd[1]);
	dup2(pointer->fd[0], STDIN_FILENO);
	dup2(pointer->pipe[WRITE_END], STDOUT_FILENO);
	execute_cmd(argv[i], envp);
}

void	pipe_out(char **argv, char **envp, t_pipe *pointer, int i)
{
	close(pointer->pipe[WRITE_END]);
	close(pointer->fd[0]);
	dup2(pointer->pipe[READ_END], STDIN_FILENO);
	dup2(pointer->fd[1], STDOUT_FILENO);
	execute_cmd(argv[i], envp);
}

int pipex_bonus(int argc, char **argv, char **envp)
{
	int num_cmd;
	t_pipe item;

	num_cmd = argc - 3;
	pipe(item.pipe);
	item.pid = fork();
	if (item.pid < 0)
		exit(127);
	if (item.pid == 0)
	{
		//infile to pipe
		check_setup_first(argv, envp, &item);
		for(int i = 2; i < argc - 1; i++){
			//pipe in
			item.pid = fork();
			if (item.pid == 0)
				pipe_in(argv, envp, &item, i);
			else
				pipe_out(argv, envp, &item, i);
		}
	}
	else
	{
		//pipe to outfile
		check_final_setup(argc, argv, envp, &item);
	}
	return (0);
}

int main(int argc, char **argv, char **envp)
{
	if (argc >= 5)
		pipex_bonus(argc, argv, envp);
	else
		return (1);
	return (0);
}


/**
 * ./pipex infile cmd1 cmd2 outfile
 * 				1child = 1pipe 
 * ./pipex infile cmd1 cmd2 cmd3 outfile
 */ 
