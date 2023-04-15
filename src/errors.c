/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 21:20:06 by glacroix          #+#    #+#             */
/*   Updated: 2023/04/15 22:01:49 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/**
 * It's a function that takes a format string and a variable number of 
 * arguments, and prints the formatted string to the standard error output
 * 
 * @param format The format string.
 */

void	print_error(char *format, ...)
{
	va_list	ap;
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == 's')
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

void	error_log(void)
{
	perror("");
	exit(EXIT_FAILURE);
}
