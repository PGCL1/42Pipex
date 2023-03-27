/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:24:23 by glacroix          #+#    #+#             */
/*   Updated: 2023/03/27 18:49:16 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

extern int errno;

void error_log(void)
{
	perror("Error printed by perror: ");
	ft_putstr_fd(strerror(errno), 1);
	exit(EXIT_FAILURE);
}