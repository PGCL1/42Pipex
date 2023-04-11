/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:19:45 by glacroix          #+#    #+#             */
/*   Updated: 2023/03/24 17:28:34 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *s, int c)
{
	int	x;

	x = ft_strlen(s);
	while (x >= 0)
	{
		if (s[x] == (char)c)
			return ((char *)&s[x]);
		x--;
	}
	return (NULL);
}
