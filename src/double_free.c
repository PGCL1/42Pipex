/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:15:54 by glacroix          #+#    #+#             */
/*   Updated: 2023/04/11 14:35:09 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * It frees a double pointer
 * 
 * @param pointer The pointer to the array of strings.
 */

void	double_free(char **pointer)
{
	int	i;

	i = -1;
	while (pointer[++i] != NULL)
		free(pointer[i]);
	free(pointer);
}
