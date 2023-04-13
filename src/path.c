/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:33:18 by glacroix          #+#    #+#             */
/*   Updated: 2023/04/13 16:50:28 by glacroix         ###   ########.fr       */
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
/* char	*find_real_path(char **envp, char *cmd)
{
	int  j;
	char **num_cmd;
	char **split_envp;
	char *possible_path;
	char *real_path;

	j = -1;
	num_cmd = ft_split(cmd, 32);		
	split_envp = find_possible_path(envp);
	while (split_envp[++j] != NULL)
	{
		possible_path = ft_strjoin(split_envp[j], "/");
		real_path = ft_strjoin(possible_path, num_cmd[0]);
		free(possible_path);
		if (access(real_path, X_OK) == 0)
		{
			double_free(num_cmd);
			double_free(split_envp);
			return (real_path);
		}
		else
			free(real_path);
	}
	double_free(num_cmd);
	double_free(split_envp);
	return (cmd);
} */

char    *find_real_path(char **envp, char *cmd)
{
    char    **args;
    char    **paths;
    char    *slash;
    char    *path;
    int     i;
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

/* int main(int argc, char **argv, char **envp)
{
	char *result;
	char *cmd;
	if (argc > 0)
	{
		atexit(find_leaks);
		cmd = argv[1];
		result = find_real_path(envp, cmd);
		printf("%s", result);
	}
	//free(result);
	return (0);
} */
