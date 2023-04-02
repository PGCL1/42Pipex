/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:04:23 by glacroix          #+#    #+#             */
/*   Updated: 2023/04/02 21:15:05 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/** 
 * Objective is to find the path associated to the command
 * we will need to find the line in env[i] = "PATH=" 
 * need to check if the command exists within the path
*/

void	execute_cmd(char *cmd, char **envp)
{
	char	**args;
	
	args = malloc(sizeof(char *) * 3);
	args[0] = ft_strdup("bash");
	args[1] = ft_strdup("-c");
	args[2] = ft_strdup(cmd);
	execve("/bin/bash", args, envp);
	
}

void	first_child(char **argv, char **envp, t_pipe *pointer)
{
	pointer->fd[0] = open(argv[1], O_RDWR, 0644);
	if (pointer->fd[0] < 0) // no such file or directory
	{
		print_error("pipex: %s: %s\n", argv[1], strerror(errno));
		exit(EXIT_FAILURE);
	}
	if (access(argv[1], R_OK) < 0)
		print_error("pipex: %s: %s", argv[1], strerror(errno)); 
	dup2(pointer->fd[0], STDIN_FILENO);
	close(pointer->pipe[READ_END]);
	dup2(pointer->pipe[WRITE_END], STDOUT_FILENO);
	close(pointer->pipe[WRITE_END]);
	//first command doesn't exist
	execute_cmd(argv[2], envp);
}

void	second_child(char **argv, char **envp, t_pipe *pointer)
{
	pointer->fd[1] = open(argv[4], O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (pointer->fd[1] < 0) // no such file or directory
		error_log();
	if (access(argv[4], R_OK | W_OK) == -1)
		print_error("pipex: %s: command not found", argv[4]);
	dup2(pointer->pipe[READ_END], STDIN_FILENO);
	close(pointer->pipe[READ_END]);
	dup2(pointer->fd[1], STDOUT_FILENO);
	//access second command doesn't exist
	execute_cmd(argv[3], envp);
}

 char	*find_path(char **envp, char *cmd)
{
	int		j;
	char	**possible_path;
	char	**num_cmd;
	char	*path;

	j = 0;
	while (ft_strnstr((envp[j]), "PATH=", 5) == 0)
		j++;
	possible_path = ft_split(envp[j] + 5, ':');
	j = -1;
	if (access(cmd, X_OK) == 0)
		return (cmd);
	while (possible_path[++j] != NULL)
	{
		possible_path[j] = ft_strjoin(possible_path[j], "/");
		num_cmd = ft_split(cmd, ' ');
		path = ft_strjoin(possible_path[j], num_cmd[0]);
		if (access(path, X_OK) == 0)
			return (path);
		else
			free(path);
	}
	return (NULL);
}
