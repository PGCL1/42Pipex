/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:44:12 by glacroix          #+#    #+#             */
/*   Updated: 2023/03/24 17:27:18 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	j;
	size_t	i;
	size_t	x;

	x = ft_strlen((char *)src);
	j = 0;
	while (dst[j] && j < dstsize)
		j++;
	i = 0;
	while (src[i] && i + j + 1 < dstsize)
	{
		dst[j + i] = src[i];
		i++;
	}
	if (i != 0)
		dst[i + j] = 0;
	return (x + j);
}
