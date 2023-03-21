/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:04:23 by glacroix          #+#    #+#             */
/*   Updated: 2023/03/21 13:15:29 by glacroix         ###   ########.fr       */
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
	char *path;
	
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
		printf("Path is %s\n", path);	
	}
	return ("ERROR");
}

int main(int argc, char **argv, char **envp)
{
	char *path;
	char *cmd = argv[1];
	if (argc == 2)
	{
		path = find_path(envp, cmd);
		printf("%s", path);
	}
	return (0);
}
