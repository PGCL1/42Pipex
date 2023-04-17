/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 22:23:15 by glacroix          #+#    #+#             */
/*   Updated: 2023/04/17 14:32:48 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

int main(int argc, char **argv, char **envp)
{
	int infile;
	int outfile;
	int i;
	if (argc >= 6)
	{
		if (ft_strncmp(argv[1], "heredoc", 6))
		{
			i = 3;
			outfile = open(argv[argc - 1], O_RDWR, O_CREAT, O_APPEND, 0644);
			heredoc()
		}
		else
		{
			i = 2;
			infile = open(argv[1], O_RDONLY, 0644);
			outfile = open(argv[argc - 1], O_RDWR, 0644);
		}
		while (i < argc - 2)
		{
			child_processes(argv[i++], envp);
			dup2(outfile, STDOUT_FILENO);	
		}
		
	}
	else
		print_error("Invalid Number of Arguments: %s", strerror(errno));
}

/**
 * ./pipex file cmd cmd cmd file
 * ./pipex heredoc LIMITER cmd file
 * 
*/