/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:20:00 by glacroix          #+#    #+#             */
/*   Updated: 2023/03/24 17:24:33 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(void *s1, void *s2, size_t n)
{
	size_t			p;
	unsigned char	*st1;
	unsigned char	*st2;

	st1 = ((unsigned char *)s1);
	st2 = ((unsigned char *)s2);
	p = 0;
	while (p < n)
	{
		if (st1[p] != st2[p])
			return (st1[p] - st2[p]);
		p++;
	}
	return (0);
}
