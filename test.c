/* #include <stdio.h>
#include <unistd.h>

int main()
{
 	int id = fork();
	//printf("Hello World from id: %d\n", id);
	if (id == 0)
		printf("Hello from the child\n");
	else
		printf("Hello from the parent\n");

	id = fork();
	if (id != 0){
		fork();
	}
	printf("Hello Word\n");
} */
/* 
#include <stdio.h>

extern char **environ;

int main() {

  for (; *environ; environ++) {
    printf("%s\n", *environ);
  }

  return 0;
} */

/* int main(int argc, char **argv, char **envp)
{
	char *path;
	char *cmd = argv[1];
	int i = 0;
	if (argc == 2)
	{
			path = find_path(envp, cmd);
			printf("ANS: Path with multiple args: %s\n", path);
			i++;
	}
	return (0);
	
} */
