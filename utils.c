/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:04:23 by glacroix          #+#    #+#             */
/*   Updated: 2023/03/18 18:17:09 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "./42Libft/libft.h"

/** 
 * Objective is to find the path associated to the command
 * we will need to find the line in env[i] = "PATH=" 
 * need to check if the command exists within the path
*/

char *find_path(char cmd, char **env)
{
	int i = 0;
	char *path;
	
	while (ft_strnstr(env[i], "PATH=", 5) == 0)
		i++;
	path = ft_split(env[i], ':');
	//
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