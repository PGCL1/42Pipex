/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playing_around.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:53:38 by glacroix          #+#    #+#             */
/*   Updated: 2023/03/20 14:21:50 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
//trying to program "ls -l | wc > txt_file"
int main(int argc, char **argv, char **envp)
{
	int fd_p[2], fd;
	pipe(fd_p);

	int file, status;

	//child process
	int pid = fork();
	if (pid < 0)
		perror("Something failed when creating the child process!\n");
	if (pid == 0) //child
	{
		//cmd "ls -l"
		close(fd_p[READ_END]);
		dup2(fd_p[WRITE_END], STDOUT_FILENO);
		close(fd_p[WRITE_END]);

		//execlp
		execve(path, cmd, envp);
	}
	else //parent
	{
		close(fd_p[WRITE_END]);
		pid = fork();
		if (pid < 0)
			perror("Something failed when creating the child process!\n");
		if (pid == 0) //child
		{
			//cmd "wc"
			close(fd_p[WRITE_END]);
			dup2(fd_p[READ_END], STDIN_FILENO);
			close(fd_p[READ_END]);

			//execlp
			execve(path, cmd, envp);
			execlp("/usr/bin/wc", "wc", NULL);
		}
		else
			close(fd_p[WRITE_END]);
	}
	wait(&status);
	wait(&status);

	return (0);
}