/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 19:33:31 by glacroix          #+#    #+#             */
/*   Updated: 2023/04/06 15:09:54 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int main(int argc, char **argv, char **envp)
{
	if (argc >= 5)
		pipex_bonus(argc, argv, envp);
	else
		print_error("pipex: %s", strerror(22));
	return (0);
}
