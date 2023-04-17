/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:04:23 by glacroix          #+#    #+#             */
/*   Updated: 2023/04/15 22:15:54 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/**
 * It opens the file, checks for errors, and then executes the command.
 * 
 * @param argv The arguments passed to the program.
 * @param envp the environment variables
 * @param pointer a pointer to a t_pipe structure
 */

void	first_child(char **argv, char **envp, t_pipe *pointer)
{
	int	flag;

	flag = 0;
	pointer->fd[0] = open(argv[1], O_RDWR, 0644);
	if (pointer->fd[0] < 0)
	{
		print_error("pipex: %s: %s\n", argv[1], strerror(2));
		exit(EXIT_FAILURE);
	}
	if (access(argv[1], R_OK) < 0)
		print_error("pipex: %s: %s\n", argv[1], strerror(13));
	dup2(pointer->fd[0], STDIN_FILENO);
	close(pointer->pipe[READ_END]);
	dup2(pointer->pipe[WRITE_END], STDOUT_FILENO);
	close(pointer->pipe[WRITE_END]);
	execute_cmd(argv[2], envp, flag);
}

void	second_child(char **argv, char **envp, t_pipe *pointer)
{
	int	flag;

	flag = 1;
	pointer->fd[1] = open(argv[4], O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (pointer->fd[1] < 0)
		error_log();
	if (access(argv[4], R_OK | W_OK) == -1)
		print_error("pipex: %s: %s\n", argv[4], strerror(13));
	dup2(pointer->pipe[READ_END], STDIN_FILENO);
	close(pointer->pipe[READ_END]);
	dup2(pointer->fd[1], STDOUT_FILENO);
	execute_cmd(argv[3], envp, flag);
}

/**
 * It executes the command
 * 
 * @param cmd the command to execute
 * @param envp the environment variables
 * @param flag This is a pointer to an integer that is used to determine whether
 *  or not the program should exit after an error.
 */

void	execute_cmd(char *cmd, char **envp, int flag)
{
	char	**args;

	if (check_cmd(cmd) == 1)
		return ;
	if (access(find_real_path(envp, cmd), X_OK) == -1)
	{
		if (errno == 13)
		{
			print_error("pipex: %s: %s\n", cmd, strerror(errno));
			if (flag == 1)
				exit(126);
		}
		else if (errno == 2)
		{
			print_error("pipex: %s: command not found\n", cmd);
			if (flag == 1)
				exit(127);
		}
	}
	else
	{
		args = find_cmd(cmd);
		execve(find_real_path(envp, clean_cmd_0(cmd)), args, envp);
	}	
}
