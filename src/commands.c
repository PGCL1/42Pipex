/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 11:41:58 by glacroix          #+#    #+#             */
/*   Updated: 2023/04/14 14:58:40 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	**find_cmd(char *cmd)
{
	if (ft_strchr(cmd, 34))
		return(ft_split(cmd, 34));
	else if (ft_strchr(cmd, 39))
		return(ft_split(cmd, 39));
	else
		return(ft_split(cmd, 32));
}

char *clean_cmd_0(char *cmd)
{
	char **args;
	char *result;

	args = find_cmd(cmd);
	result = ft_strtrim(args[0], " \\'\"");
	double_free(args);
	return (result);
}

int check_cmd(char *cmd)
{
	if (ft_strnstr(cmd, ".sh", ft_strlen(cmd)))
	{
		if (ft_strtrim(cmd, " \\'\"") != NULL)
			return (1);
		else
			return (0);
	}
	return (0);
}

/* int main(int argc, char **argv, char **envp)
{
	if (argc > 0)
	{
		char *cmd = argv[1];
		printf("Clean cmd %s", clean_cmd_0(cmd));
		return (0);
	}
} */