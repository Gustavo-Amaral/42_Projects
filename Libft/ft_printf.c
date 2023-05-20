/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 20:55:11 by gamaral           #+#    #+#             */
/*   Updated: 2023/05/20 23:00:20 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_conversion(va_list args, const char format)
{
	int	print_length;

	print_length = 0;
	if (format == 'c')
		print_length += ft_print_char(va_arg(args, int));
	else if (format == 's')
		print_length += ft_print_str(va_arg(args, char *));
	else if (format == 'p')
		print_length += ft_print_ptr(va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		print_length += ft_print_nbr(va_arg(args, int));
	else if (format == 'u')
		print_length += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		print_length += ft_print_hex(va_arg(args, unsigned int), \
			format);
	else if (format == '%')
		print_length += write(1, "%", 1);
	else
		return (-1);
	return (print_length);
}

int	ft_printf(const char	*format, ...)
{
	va_list	args;
	int		print_length;

	va_start(args, format);
	print_length = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			print_length += check_conversion (args, *++format);
		else
		{
			ft_putchar(*format);
			print_length++;
		}
		format++;
	}
	va_end(args);
	return (print_length);
}
