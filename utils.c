/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:04:23 by glacroix          #+#    #+#             */
/*   Updated: 2023/03/21 18:34:04 by glacroix         ###   ########.fr       */
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
	static char *path;
	
	while (ft_strnstr((envp[j]), "PATH=", 5) == 0)
		j++;
	possible_path = ft_split(envp[j] + 5, ':');
	j = -1;
	while (possible_path[++j] != NULL)
	{
		possible_path[j] = ft_strjoin(possible_path[j], "/");
		path = ft_strjoin(possible_path[j], cmd);
		if (access(path, X_OK) == 0)
			return (path);
		else
			free(path);
	}
	return ("ERROR");
}

//!integrate functions cmd_count and cmd_parts into the find_path function

int cmd_count(char *cmd)
{
	//char *second_part;
	char **num_cmd;
	int i = -1;
	int count = 0;

	num_cmd = ft_split(cmd, ' ');
	while (num_cmd[++i])
		count++;
	printf("Count is %d\n", count);
	if (count == 2)
		return (1);
	else if (count > 2)
		return (3);
	return (0);
}

char *cmd_parts(char *cmd)
{
	//char *second_part;
	char **num_cmd;
	int i = -1;
	if (cmd_count(cmd) == 2)
		num_cmd = ft_split(cmd, ' ');
	return (num_cmd[0]);
}

int main(int argc, char **argv, char **envp)
{
	static char *path;
	char *cmd = argv[1];
	char **part;
	int i = 0;
	if (argc == 2)
	{
/* 		while (part[i] != NULL)
		{
			path = find_path(envp, part[i]);
			printf("ANS: Path with multiple args: %s\n", path);
			i++;
		}
		printf("ANS: Path with multiple args: %s\n", path); */
		if (cmd_count(cmd) == 1)
		{
			part = ft_split(cmd, ' ');
			i = -1;
			while (part[++i])
				printf("There are options in the command: %s\n", part[i]);
		}
		else
		{
			path = find_path(envp, cmd);
			printf("There are no options in the command: %s\n", path);
		}
			
	}
	return (0);
	
}
