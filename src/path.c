/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:33:18 by glacroix          #+#    #+#             */
/*   Updated: 2023/04/19 18:50:02 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/* void find_leaks()
{
	system("leaks -q a.out");
	return;
} */

char	**path_find_possible(char **envp)
{
	int		j;
	char	**possible_path;

	j = 0;
	possible_path = NULL;
	while (envp[j] != NULL)
	{
		if (ft_strncmp(envp[j], "PATH=", 5) == 0)
			break ;
		j++;
	}
	possible_path = ft_split(envp[j] + 5, ':');
	return (possible_path);
}

char	*path_or_command(char *cmd, char **envp, char **args)
{
	char	**paths;
	char	*slash;
	char	*path;
	int		i;

	i = -1;
	paths = path_find_possible(envp);
	while (!ft_strnstr(cmd, ".sh", ft_strlen(cmd)) && paths[++i] != NULL)
	{
		slash = ft_strjoin(paths[i], "/");
		path = ft_strjoin(slash, args[0]);
		free(slash);
		if (access(path, X_OK) == 0)
		{
			free_pointer2pointer(paths);
			free_pointer2pointer(args);
			return (path);
		}
		free(path);
	}
	free_pointer2pointer(paths);
	free_pointer2pointer(args);
	return (cmd);
}

char	*path_found(char **envp, char *cmd)
{
	char	**args;
	char	*result;
	int		i;

	if (*envp == NULL && access(cmd, X_OK) == -1)
		return (NULL);
	if (access(cmd, X_OK) == 0)
		return (cmd);
	i = -1;
	args = ft_split(cmd, ' ');
	result = path_or_command(cmd, envp, args);
	return (result);
}
