/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 11:41:58 by glacroix          #+#    #+#             */
/*   Updated: 2023/04/19 18:56:30 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	**cmd_find(char *cmd)
{
	if (ft_strchr(cmd, 39))
		return (ft_split(cmd, 39));
	else if (ft_strchr(cmd, 34))
		return (ft_split(cmd, 34));
	else
		return (ft_split(cmd, 32));
}

char	*cmd_find_args0(char *cmd)
{
	char	**args;
	char	*result;

	args = cmd_find(cmd);
	result = ft_strtrim(args[0], " \\'\"");
	free_pointer2pointer(args);
	return (result);
}

int	cmd_check(char *cmd)
{
	if (ft_strnstr(cmd, ".sh", ft_strlen(cmd)))
	{
		if (ft_strchr(cmd, 32) != NULL)
			return (1);
		if (!ft_strnstr(cmd, "./", 2) && !ft_strchr(cmd, '/'))
		{
			error_print("pipex: %s: command not found\n", cmd);
			return (1);
		}
	}
	return (0);
}

/* int main(int argc, char **argv, char **envp)
{
	if (argc > 0)
	{
		char *cmd = argv[1];
		printf("Check cmd is %d\n", check_cmd(cmd));
	}
	return 0;
}  */