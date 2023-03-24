/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:04:23 by glacroix          #+#    #+#             */
/*   Updated: 2023/03/24 16:41:53 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/** 
 * Objective is to find the path associated to the command
 * we will need to find the line in env[i] = "PATH=" 
 * need to check if the command exists within the path
*/

char *find_path(char **envp, char *cmd)
{
	int j = 0;
	char **possible_path;
	char **num_cmd;
	char *path;
	
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
	/* 	printf("At position %d, path is %s\n", j, path); */
		if (access(path, X_OK) == 0)
			return (path);
		else
			free(path);
	}
	return ("ERROR");
}

int execute_cmd(char *cmd, char **envp)
{
	char *path;
	char **num_cmd;
	
	path = find_path(envp, cmd);
	num_cmd = ft_split(cmd, ' ');
	return (execve(path, num_cmd, envp));	
}

void first_child(char **argv, char **envp, int *fdp)
{
	int infile;
	
	infile = open(argv[1], O_RDWR, 0644);
	if (infile < 0)
		exit(EXIT_FAILURE);
	if (access(argv[1], R_OK) < 0)
		exit(EXIT_FAILURE);
	dup2(infile, STDIN_FILENO);
	close(fdp[READ_END]);
	dup2(fdp[WRITE_END], STDOUT_FILENO);
	close(fdp[WRITE_END]);
	execute_cmd(argv[2], envp);
}

void second_child(char **argv, char **envp, int *fdp)
{
	int outfile;
	
	outfile = open(argv[4], O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (outfile < 0)
		perror("Outfile doesn't exist");
	dup2(fdp[READ_END], STDIN_FILENO);
	close(fdp[READ_END]);
	dup2(outfile, STDOUT_FILENO);
	execute_cmd(argv[3], envp);
}
