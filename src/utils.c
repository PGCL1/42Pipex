/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:04:23 by glacroix          #+#    #+#             */
/*   Updated: 2023/04/03 19:54:23 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * It executes the command
 * 
 * @param cmd the command to execute
 * @param envp the environment variables
 * @param flag This is a pointer to an integer that is used to determine whether
 *  or not the program should exit after an error.
 */

void	execute_cmd(char *cmd, char **envp, int *flag)
{
	char	**args;

	artificial_bash(cmd, flag);
	args = malloc(sizeof(char *) * 3);
	args[0] = ft_strdup("bash");
	args[1] = ft_strdup("-c");
	args[2] = ft_strdup(cmd);
	if (find_path(envp, cmd) == NULL)
	{
		print_error("pipex: %s: command not found\n", cmd);
		if (*flag == 1)
			exit(127);
	}
	else
		execve("/bin/bash", args, envp);
}

/**
 * It checks if the command is a shell script and if it is, it checks if it's
 * executable. If it's not, it prints an error message
 * 
 * @param cmd the command to be executed
 * @param flag This is a pointer to an integer that is used to determine if the
 * program is being run in the background or not.
 */

void	artificial_bash(char *cmd, int *flag)
{
	if (ft_strnstr(cmd, ".sh", ft_strlen(cmd)) != NULL
		&& access(cmd, X_OK) == -1)
	{
		if (*flag == 1)
		{
			print_error("pipex: %s: %s\n", cmd, strerror(errno));
			exit(EXIT_FAILURE);
		}
		else
			print_error("pipex: %s: %s\n", cmd, strerror(errno));
	}
}

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
		print_error("pipex: %s: %s", argv[1], strerror(13));
	dup2(pointer->fd[0], STDIN_FILENO);
	close(pointer->pipe[READ_END]);
	dup2(pointer->pipe[WRITE_END], STDOUT_FILENO);
	close(pointer->pipe[WRITE_END]);
	execute_cmd(argv[2], envp, &flag);
}

/**
 * It opens the file specified by the user, and then it duplicates the read end
 * of the pipe to the standard input, and the write end of the file to the 
 * standard output
 * 
 * @param argv the arguments passed to the program
 * @param envp the environment variables
 * @param pointer a pointer to the t_pipe structure
 */

void	second_child(char **argv, char **envp, t_pipe *pointer)
{
	int	flag;

	flag = 1;
	pointer->fd[1] = open(argv[4], O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (pointer->fd[1] < 0)
		error_log();
	if (access(argv[4], R_OK | W_OK) == -1)
		print_error("pipex: %s: %s", argv[4], strerror(13));
	dup2(pointer->pipe[READ_END], STDIN_FILENO);
	close(pointer->pipe[READ_END]);
	dup2(pointer->fd[1], STDOUT_FILENO);
	execute_cmd(argv[3], envp, &flag);
}

/**
 * It takes a command and an environment variable, and returns the path to the
 * command if it exists, or NULL if it doesn't
 * 
 * @param envp the environment variables
 * @param cmd the command that the user entered
 * 
 * @return The path to the command.
 */

char	*find_path(char **envp, char *cmd)
{
	int		j;
	char	**possible_path;
	char	**num_cmd;
	char	*path;

	if (access(cmd, X_OK) == 0)
		return (cmd);
	j = 0;
	while (ft_strnstr((envp[j]), "PATH=", 5) == 0)
		j++;
	possible_path = ft_split(envp[j] + 5, ':');
	j = -1;
	while (possible_path[++j] != NULL)
	{
		possible_path[j] = ft_strjoin(possible_path[j], "/");
		num_cmd = ft_split(cmd, ' ');
		path = ft_strjoin(possible_path[j], num_cmd[0]);
		free(possible_path[j]);
		if (access(path, X_OK) == 0)
			return (path);
		else
			free(path);
	}
	return (NULL);
}
