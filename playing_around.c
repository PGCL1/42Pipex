#include "pipex.h"
//trying to program "ls -l | wc > txt_file"
int main(int argc, char **argv)
{
	int fd1[2], fd2;
	pipe(fd1);

	int file, status;

	//child process
	int pid = fork();
	if (pid < 0)
		perror("Something failed when creating the child process!\n");
	if (pid == 0) //child
	{
		//cmd "ls -l"
		close(fd1[READ_END]);
		dup2(fd1[WRITE_END], STDOUT_FILENO);
		close(fd1[WRITE_END]);

		//execlp
		execlp("/bin/ls", "ls" "-l", NULL);
	}
	else //parent
	{
		close(fd1[WRITE_END]);
		pid = fork();
		if (pid < 0)
			perror("Something failed when creating the child process!\n");
		if (pid == 0) //child
		{
			//cmd "wc"
			close(fd1[WRITE_END]);
			dup2(fd1[READ_END], STDIN_FILENO);
			close(fd1[READ_END]);

			//execlp
			execlp("/usr/bin/wc", "wc", NULL);
		}
		else
			close(fd1[WRITE_END]);
	}
	wait(&status);
	wait(&status);

	return (0);
}