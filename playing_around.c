#include "pipex.h"
#include <string.h>

int main(int argc, char **argv)
{
	int fd[2];
	pipe(fd);

	int file;

	//child process
	int id = fork();
	if (id < 0)
		perror("Something failed when creating the child process!\n");
	if (id == 0) //child
	{
		close(fd[0]);
		file = open("viovio.txt", O_WRONLY | O_CREAT, 0666);
		char *s = "hi\nhow\nare\nyou\n";
		write(file, s, strlen(s));
		dup2(file, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(file);
	}
	else //parent
	{
		close(fd[1]);
		int file1 = open("viovio2.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
		dup2(file1, STDOUT_FILENO);
		dup2(fd[0], STDIN_FILENO);
		const char *pathname = "/usr/bin/wc";
		int tbd = execve(pathname, &argv[1], NULL);
		if (tbd == -1)
			exit(EXIT_FAILURE);
		close(fd[1]);
	}




}