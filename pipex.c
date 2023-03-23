#include "pipex.h"
//trying to program "ls -l | wc > txt_file"
int pipex(char **envp, char **argv)
{
	int fdp[2];
	int fd;
	int file, status;
	pipe(fdp);

	int pid = fork(); //processor id (pid)
	if (pid < 0)
		perror("Something failed when creating the first child process!\n");
	//!first child function
	if (pid == 0) //child
	{
		//cmd "ls -l"
		close(fdp[READ_END]);
		dup2(fdp[WRITE_END], STDOUT_FILENO);
		close(fdp[WRITE_END]);

		//execlp
		execve(path, cmd, env);
	}
	else //parent
	{
		close(fdp[WRITE_END]);
		pid = fork();
		if (pid < 0)
			perror("Something failed when creating the second child process!\n");
		if (pid == 0) //child
		{
			//cmd "wc"
			fd = open(FILE_NAME, O_RDWR, O_TRUNC, O_CREAT, 0664);
			dup2(fdp[READ_END], STDIN_FILENO);
			close(fdp[READ_END]);

			dup2(fd, STDOUT_FILENO);

			//execlp
			execve(path, cmd, env);
		}
		else
			close(fdp[READ_END]);
	}
	wait(&status);
	wait(&status);

	return (0);
}
