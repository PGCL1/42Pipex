/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:05:40 by glacroix          #+#    #+#             */
/*   Updated: 2023/03/30 18:34:14 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


int	pipex(char **argv, char **envp)
{
	t_pipe	pi;
	
	pipe(pi.pipe);
	pi.pid = fork();
	if (pi.pid < 0)
		perror("");
	if (pi.pid == 0)
		first_child(argv, envp, &pi);
	else
	{
		close(pi.pipe[WRITE_END]);
		second_child(argv, envp, &pi);
		close(pi.pipe[READ_END]);
	}
	wait(&pi.status);
	wait(&pi.status);
	return (0);
}
