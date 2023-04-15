/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:33:18 by glacroix          #+#    #+#             */
/*   Updated: 2023/04/15 22:07:39 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/* void find_leaks()
{
	system("leaks -q a.out");
	return;
} */

char	**find_possible_path(char **envp)
{
	int		j;
	char	**possible_path;

	j = 0;
	while (ft_strnstr((envp[j]), "PATH=", 5) == 0)
		j++;
	possible_path = ft_split(envp[j] + 5, ':');
	return (possible_path);
}

char	*find_real_path(char **envp, char *cmd)
{
	char	**args;
	char	**paths;
	char	*slash;
	char	*path;
	int		i;

	i = -1;
	args = ft_split(cmd, ' ');
	paths = find_possible_path(envp);
	while (!ft_strnstr(cmd, ".sh", ft_strlen(cmd)) && paths[++i] != NULL)
	{
		slash = ft_strjoin(paths[i], "/");
		path = ft_strjoin(slash, args[0]);
		free(slash);
		if (access(path, X_OK) == 0)
		{
			double_free(paths);
			double_free(args);
			return (path);
		}
		free(path);
	}
	double_free(paths);
	double_free(args);
	return (cmd);
}
