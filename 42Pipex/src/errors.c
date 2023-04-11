/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 21:16:19 by glacroix          #+#    #+#             */
/*   Updated: 2023/04/03 19:55:28 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * It prints the error message to the standard error output and exits 
 * the program with a failure status
 */

void	error_log(void)
{
	perror("");
	exit(EXIT_FAILURE);
}
