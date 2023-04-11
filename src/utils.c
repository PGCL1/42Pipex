/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:04:23 by glacroix          #+#    #+#             */
/*   Updated: 2023/04/11 17:26:03 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	execute_cmd(argv[2], envp, &flag);
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
	execute_cmd(argv[3], envp, &flag);
} 

char	**find_cmd(char *cmd)
{
	if (ft_strchr(cmd, 34))
		return(ft_split(cmd, 34));
	else if (ft_strchr(cmd, 39))
		return(ft_split(cmd, 39));
	else
		return(ft_split(cmd, 32));
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

	j = 0;
	while (ft_strnstr((envp[j]), "PATH=", 5) == 0)
		j++;
	possible_path = ft_split(envp[j] + 5, ':');
	j = -1;
	while (!ft_strnstr(cmd, ".sh", ft_strlen(cmd)) 
			&& possible_path[++j] != NULL)
	{
		possible_path[j] = ft_strjoin(possible_path[j], "/");
		num_cmd = find_cmd(cmd);
		path = ft_strjoin(possible_path[j], num_cmd[0]);
		double_free(num_cmd);
		if (access(path, X_OK) == 0)
			return (path);
		else
			free(path);
	}
	return (cmd);
}

char *clean_cmd_0(char *cmd)
{
	char **args;

	args = find_cmd(cmd);
	args[0] = ft_strtrim(args[0], " \\'\"");
	return (args[0]);
}

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
	
 	if (access(find_path(envp, clean_cmd_0(cmd)), X_OK) == -1)
	{
		//no permissions
		if (errno == 13)
		{
			print_error("pipex: %s: %s\n", clean_cmd_0(cmd), strerror(errno));
			if (*flag == 1)
				exit(126);
		}
		else if (errno == 2)
		{
			print_error("pipex: %s: command not found\n", clean_cmd_0(cmd));
			if (*flag == 1)
				exit(127);	
		}
	}
	else
	{
		args = find_cmd(cmd);
		execve(find_path(envp, clean_cmd_0(cmd)), args, envp);
	}	
}

/* int main(int argc, char **argv, char **envp)
{
	if (argc > 0)
	{
		char **args;

		int i = 0;
		args = find_cmd(argv[1]);
		printf("Clean %s\n", clean_cmd_0(args[0]));
		while (args[i])
			printf("%s\n" , args[i++]);
		return (0);
	}
}  */

/**
 * cmd = ls -l
 */