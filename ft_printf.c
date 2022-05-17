/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afridasufi <afridasufi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:18:03 by afridasufi        #+#    #+#             */
/*   Updated: 2022/04/26 15:31:43 by afridasufi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_char(char c)
{
	return (write(1, &c, 1));
}

int	write_str(char *string)
{
	int	bytes;
	int	index;

	index = -1;
	bytes = 0;
	if (!string)
		return (write (1, "(null)", 6));
	while (string[++index])
		bytes += write (1, &string[index], 1);
	return (bytes);
}

int	specifier(const char *formt, int i, va_list args)
{
	int	bytes;

	bytes = 0;
	if (formt[i] == 'c')
		bytes = write_char(va_arg(args, int));
	else if (formt[i] == 's')
		bytes = write_str(va_arg(args, char *));
	else if (formt[i] == 'p')
		bytes = write_ptr(va_arg(args, unsigned long long), 0);
	else if (formt[i] == 'd' || formt[i] == 'i')
		bytes = write_int(va_arg(args, int), 0);
	else if (formt[i] == 'u')
		bytes = write_unint(va_arg(args, int), 0);
	else if (formt[i] == 'x')
		bytes = write_hex(va_arg(args, int), 0);
	else if (formt[i] == 'X')
		bytes = write_hexa(va_arg(args, int), 0);
	else if (formt[i] == '%')
		bytes = write(1, "%", 1);
	return (bytes);
}

int	ft_printf(const char *formt, ...)
{
	va_list	args;
	int		index;
	int		sum_bytes;

	va_start(args, formt);
	index = 0;
	sum_bytes = 0;
	while (formt[index])
	{
		if (formt[index] == '%')
		{
			sum_bytes += specifier(formt, index + 1, args);
			index++;
		}
		else
			sum_bytes += write(1, &formt[index], 1);
		index++;
	}
	va_end(args);
	return (sum_bytes);
}
