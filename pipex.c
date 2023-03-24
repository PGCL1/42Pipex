/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:05:40 by glacroix          #+#    #+#             */
/*   Updated: 2023/03/24 18:15:44 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


int	pipex(char **argv, char **envp)
{
	int	fdp[2];
	int	status;
	int	pid;

	pipe(fdp);
	pid = fork();
	if (pid < 0)
		perror(FIRST_CHILD_FAIL);
	if (pid == 0)
		first_child(argv, envp, fdp);
	else
	{
		close(fdp[WRITE_END]);
		pid = fork();
		if (pid < 0)
			perror(SECOND_CHILD_FAIL);
		if (pid == 0)
			second_child(argv, envp, fdp);
		close(fdp[READ_END]);
	}
	wait(&status);
	wait(&status);
	return (0);
}
