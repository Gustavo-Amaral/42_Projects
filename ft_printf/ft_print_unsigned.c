/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 19:16:01 by gamaral           #+#    #+#             */
/*   Updated: 2023/05/20 17:32:28 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_unsigned_nbr(unsigned int num)
{
	if (num < 10)
	{
		ft_putchar(num + 48);
	}
	else
	{
		ft_put_unsigned_nbr(num / 10);
		ft_putchar((num % 10) + 48);
	}
}

int	ft_print_unsigned(unsigned int num)
{
	int	print_length;

	print_length = 0;
	ft_put_unsigned_nbr(num);
	if (num == 0)
		print_length++;
	while (num != 0)
	{
		num /= 10;
		print_length++;
	}
	return (print_length);
}
