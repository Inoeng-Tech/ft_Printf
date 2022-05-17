/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afridasufi <afridasufi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:10:58 by afridasufi        #+#    #+#             */
/*   Updated: 2022/04/27 15:05:16 by afridasufi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int	ft_printf(const char *formt, ...);
int	specifier(const char *formt, int i, va_list args);
int	write_char(char c);
int	write_str(char *chr);
int	write_hex(unsigned int n, int bytes);
int	write_hexa(unsigned int n, int bytes);
int	write_unint(unsigned int n, int bytes);
int	write_int(int n, int bytes);
int	write_ptr(unsigned long long n, int bytes);
#endif
