/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:00:10 by glacroix          #+#    #+#             */
/*   Updated: 2023/03/24 17:09:58 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	if (argc == 5)
	{
		pipex(argv, envp);
	}
	else if (argc > 5)
	{
		perror("More than 5 arguments to satisfy PIPEX's requirements");
		exit(EXIT_FAILURE);
	}
	else
	{
		perror("Not enough arguments to satisfy PIPEX's requirements");
		exit(EXIT_FAILURE);
	}
	return (0);
}
