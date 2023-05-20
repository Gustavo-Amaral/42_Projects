/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 19:15:39 by gamaral           #+#    #+#             */
/*   Updated: 2023/05/20 23:00:20 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	hex_len(unsigned int num)
{
	int	print_length;

	print_length = 0;
	if (num == 0)
		print_length++;
	while (num != 0)
	{
		num /= 16;
		print_length++;
	}
	return (print_length);
}

static void	hexing(char *hex_str, unsigned int num, const char c)
{
	while (num != 0)
	{
		if ((num % 16) <= 9)
			*hex_str++ = ((num % 16) + '0');
		else
		{
			if (c == 'x')
				*hex_str++ = ((num % 16) - 10 + 'a');
			else if (c == 'X')
				*hex_str++ = ((num % 16) - 10 + 'A');
		}
		num /= 16;
	}
	*hex_str = '\0';
}

int	ft_print_hex(unsigned int num, const char c)
{
	int		print_length;
	char	*hex_str;

	print_length = hex_len(num);
	hex_str = malloc(sizeof(char) * hex_len(num) + 1);
	if (!hex_str)
		return (0);
	if (num == 0)
		ft_putchar(num + '0');
	hexing(hex_str, num, c);
	ft_revstr(hex_str);
	ft_putstr(hex_str);
	free(hex_str);
	return (print_length);
}
