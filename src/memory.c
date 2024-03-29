/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 21:16:19 by glacroix          #+#    #+#             */
/*   Updated: 2023/04/19 18:47:26 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/* static void	system_exec(char *cmdtemplate)
{
	FILE* fp = popen(cmdtemplate, "r");
    if (fp == NULL)
	{
		ft_putstr_fd("Error opening command", 2);
		ft_putstr_fd(cmdtemplate, 2);
		return ;
    }
	char output[1024];
	size_t n = fread(output, 1, sizeof(output), fp);
	output[n] = '\0';
	ft_putstr_fd(output, 2);
}
static void	exit_checks(void)
{
    char cmdtemplate[1024];
    ft_putstr_fd("\n\n******************************************\n", 2);
    ft_putstr_fd("Open fds:\n", 2);
    sprintf(cmdtemplate, "lsof -p %d | grep CHR", getpid());
    system_exec(cmdtemplate);
    ft_putstr_fd("\nLeaks:\n", 2);
    sprintf(cmdtemplate, "leaks %d", getpid());
    system_exec(cmdtemplate);
    ft_putstr_fd("******************************************\n", 2);
} */

/* void	ft_leaks(void)
{
	system_exec("");
	exit_checks();
	return ;
} */

void	free_pointer2pointer(char **pointer)
{
	int	i;

	i = 0;
	while (pointer[i] != NULL)
		free(pointer[i++]);
	free(pointer);
}
