/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:35:29 by glacroix          #+#    #+#             */
/*   Updated: 2023/03/24 17:36:45 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*t;

	t = lst;
	if (!lst)
		return (NULL);
	while (t)
	{
		if (!(t -> next))
			return (t);
		t = t -> next;
	}
	return (t);
}
