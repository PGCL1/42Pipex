/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:00:10 by glacroix          #+#    #+#             */
/*   Updated: 2023/04/06 15:06:01 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void ft_leaks(void)
{
	printf("hola\n");
	system("leaks pipex");
}

int	main(int argc, char **argv, char **envp)
{
	atexit(ft_leaks);
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
///Users/glacroix/.brew/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/munki:/Users/glacroix/.brew/bin