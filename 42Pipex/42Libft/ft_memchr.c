/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:41:11 by glacroix          #+#    #+#             */
/*   Updated: 2023/03/24 17:24:11 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *s, int c, size_t n)
{
	size_t	p;

	p = 0;
	while (p < n)
	{
		if ((((unsigned char *)s)[p]) == (unsigned char) c)
			return ((unsigned char *)s + p);
		p++;
	}
	return (0);
}
