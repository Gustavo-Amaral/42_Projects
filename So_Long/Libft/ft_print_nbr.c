/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 19:15:45 by gamaral           #+#    #+#             */
/*   Updated: 2023/06/15 21:08:08 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int num)
{
	if (num < 0)
		return (-1 * num);
	else
		return (num);
}

static int	numlen(int num)
{
	int	print_length;

	print_length = 0;
	num = ft_abs(num);
	while (num != 0)
	{
		num /= 10;
		print_length++;
	}
	return (print_length);
}

int	ft_print_nbr(int num)
{
	int	print_length;

	print_length = 0;
	ft_putnbr(num);
	if (num <= 0)
		print_length++;
	print_length += numlen(num);
	return (print_length);
}
