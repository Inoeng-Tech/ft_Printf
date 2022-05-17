/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afridasufi <afridasufi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 12:53:06 by afridasufi        #+#    #+#             */
/*   Updated: 2022/04/26 15:36:08 by afridasufi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_ptr(unsigned long long n, int bytes)
{
	int	rem;

	if (bytes == 0)
		bytes += write(1, "0x", 2);
	if (n > 15)
		bytes = write_ptr(n / 16, bytes);
	rem = n % 16;
	bytes += write(1, &"0123456789abcdef"[rem], 1);
	return (bytes);
}

int	write_int(int n, int bytes)
{
	char	rem;

	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		bytes += write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
		bytes = write_int(n / 10, bytes);
	rem = n % 10 + '0';
	bytes += write(1, &rem, 1);
	return (bytes);
}

int	write_unint(unsigned int n, int bytes)
{
	char	rem;

	if (n < 0)
		return (0);
	if (n > 9)
		bytes = write_unint(n / 10, bytes);
	rem = n % 10 + '0';
	bytes += write(1, &rem, 1);
	return (bytes);
}

int	write_hex(unsigned int n, int bytes)
{
	int	rem;

	if (n < 0)
		return (0);
	if (n > 15)
		bytes = write_hex(n / 16, bytes);
	rem = n % 16;
	bytes += write(1, &"0123456789abcdef"[rem], 1);
	return (bytes);
}

int	write_hexa(unsigned int n, int bytes)
{
	int	rem;

	if (n < 0)
		return (0);
	if (n > 15)
		bytes = write_hexa(n / 16, bytes);
	rem = n % 16;
	bytes += write(1, &"0123456789ABCDEF"[rem], 1);
	return (bytes);
}
