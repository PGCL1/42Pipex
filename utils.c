/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:04:23 by glacroix          #+#    #+#             */
/*   Updated: 2023/03/20 19:24:27 by glacroix         ###   ########.fr       */
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
	int i = 0;
	int j = 0;
	char **path;
	char *real_path;
	
	while (ft_strnstr(envp[j], "PATH=", 5) == 0)
		j++;
	path = ft_split(envp[j] + 5, ':');
	j = 0;
	//!mistake here
	while (path[j] != NULL)
		path = ft_strjoin(path, '/');
	real_path = ft_strjoin(path, cmd);
	i = 0;
	while (path[i] != NULL)
	{
		if (access(path[i], X_OK) == 0)
			return (path[i]);
		i++;		
	}
}

int main(int argc, char **argv)
{
	int i = 0;
	char **split;
	if (argc == 2)
	{
		split = ft_split(argv[1], '\n');
		while (split[i] != 0)
		{
			printf("%s ", split[i]);
			i++;
		}
		printf("%s", split[i]);
	}
	return (0);
}