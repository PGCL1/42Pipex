/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:05:05 by glacroix          #+#    #+#             */
/*   Updated: 2023/03/24 17:16:25 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *str)
{
	int				i;
	int				signage;
	unsigned int	result;

	i = 0;
	result = 0;
	signage = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i++] == 45)
			signage++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = ((str[i++] - '0') + (result * 10));
	if (result > 2147483647 && !signage)
		return (-1);
	else if (result > 2147483648 && signage)
		return (0);
	else if (signage)
		return ((int)result * -1);
	return ((int) result);
}
