/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:05:40 by glacroix          #+#    #+#             */
/*   Updated: 2023/04/19 18:20:29 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/**
 * It creates a pipe, forks, and then the child process writes to the pipe 
 * and the parent process reads from the pipe
 * 
 * @param argv The arguments passed to the program.
 * @param envp the environment variables
 * 
 * @return The return value of the last command executed.
 */

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
	if (wait(&pi.status) == -1)
		print_error("pipex: %s\n", strerror(errno));
	if (wait(&pi.status) == -1)
		print_error("pipex: %s\n", strerror(errno));
	return (0);
}
