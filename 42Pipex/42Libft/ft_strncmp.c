/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 18:13:46 by glacroix          #+#    #+#             */
/*   Updated: 2023/03/24 17:28:00 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t			i;
	unsigned char	*st1;
	unsigned char	*st2;

	st1 = ((unsigned char *)s1);
	st2 = ((unsigned char *)s2);
	i = 0;
	while ((st1[i] != '\0' || st2[i] != '\0') && i < n)
	{
		if (st1[i] != st2[i])
			return (st1[i] - st2[i]);
		i++;
	}
	return (0);
}
