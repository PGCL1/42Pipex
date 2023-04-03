/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:15:54 by glacroix          #+#    #+#             */
/*   Updated: 2023/04/03 19:40:54 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	double_free(char **pointer)
{
	int	i;

	i = 0;
	while (pointer[i] != NULL)
	{
		free(pointer[i]);
		i++;
	}
	free(pointer);
}
