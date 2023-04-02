#include "pipex.h"

void error_log(void)
{
	perror("");
	/* ft_putstr_fd(strerror(errno), 2); */
	exit(EXIT_FAILURE);
}