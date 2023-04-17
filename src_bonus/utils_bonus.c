/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 22:37:47 by glacroix          #+#    #+#             */
/*   Updated: 2023/04/15 23:17:46 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void child_processes(char *argv, char **envp)
{
	t_pipe	pi;

	pipe(pi.pipe);
	pi.pid = fork();
	if (pi.pid < 0)
		perror("");
	if (pi.pid == 0)
	{
		close(pi.pipe[WRITE_END]);
		dup2(fd[1], STDIN_FILENO);
		execute_cmd(argv, envp);
	}
	else
	{
		close(pi.pipe[READ_END]);
		dup2(fd[0], STDOUT_FILENO);
		waitpid(pid, NULL, 0);
	}
}
