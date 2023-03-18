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

	int id = fork();
	if (id != 0){
		fork();
	}
	printf("Hello Word\n");
} */