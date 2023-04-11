/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:00:10 by glacroix          #+#    #+#             */
/*   Updated: 2023/04/03 19:25:50 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	if (argc == 5)
	{
		if (!*envp)
			*envp = "PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:";
		pipex(argv, envp);
	}
	else
	{
		ft_putstr_fd(strerror(22), 2);
		exit(EXIT_FAILURE);
	}
	return (0);
}

/* args = {"bash", "-c", argv[1], NULL}

execve("/bin/bash", args, NULL) */
