/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 19:37:51 by glacroix          #+#    #+#             */
/*   Updated: 2023/04/03 19:38:04 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void print_error(char *format, ...)
{
	va_list ap;
	va_start(ap, format);
	int i = 0;
	int j = 0;
	char *s;
	
	while (format[i])
	{
		if (format[i] == '%' && format[i+1] == 's')
		{
			s = va_arg(ap, char *);
			j = 0;
			while (s[j] != '\0')
				write(2, &s[j++], 1);
			i++;
		}
		else
			write(2, &format[i], 1);
		i++;
	}
	va_end(ap);
}