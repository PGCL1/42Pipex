#include "pipex.h"

int pipex(char **argv, char **envp)
{
	int fdp[2];
	int status;
	pipe(fdp);

	int pid = fork();
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
		if (pid == 0) //child
			second_child(argv, envp, fdp);
		close(fdp[READ_END]);
	}
	wait(&status);
	wait(&status);
	return (0);
}
