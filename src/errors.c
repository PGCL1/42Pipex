/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 21:16:19 by glacroix          #+#    #+#             */
/*   Updated: 2023/04/02 21:16:23 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void error_log(void)
{
	perror("");
	/* ft_putstr_fd(strerror(errno), 2); */
	exit(EXIT_FAILURE);
}