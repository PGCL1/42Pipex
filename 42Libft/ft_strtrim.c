/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:47:24 by glacroix          #+#    #+#             */
/*   Updated: 2023/03/24 17:28:47 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char *s, char *cut)
{
	size_t	size;

	if (!s || !cut)
		return (NULL);
	while (*s && ft_strchr(cut, *s))
		s++;
	size = ft_strlen(s);
	while (size && ft_strrchr(cut, s[size]))
		size--;
	return (ft_substr(s, 0, size + 1));
}
