/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:11:48 by glacroix          #+#    #+#             */
/*   Updated: 2023/04/03 16:19:47 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s1)
{
	char			*string;
	unsigned int	len;

	len = ft_strlen(s1);
	string = (malloc((len + 1) * sizeof(char)));
	if (!string)
		return (NULL);
	ft_memcpy(string, s1, len * sizeof(char));
	string[len] = 0;
	return (string);
}
