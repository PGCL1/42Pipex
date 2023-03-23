/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:00:10 by glacroix          #+#    #+#             */
/*   Updated: 2023/03/22 17:05:03 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
	if (argc == 5)
	{
		pipex(envp, argv);
	}
	else if (argc > 5)
	{
		prerror("There are more than 5 arguments to satisfy PIPEX's requirements");
	}
	else
		prerror("There are not enough arguments to satisfy PIPEX's requirements");
}