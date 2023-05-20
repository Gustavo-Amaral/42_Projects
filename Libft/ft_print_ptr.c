/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 19:15:50 by gamaral           #+#    #+#             */
/*   Updated: 2023/05/20 23:00:20 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ptr_len(unsigned long long num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

static void	ft_put_ptr(unsigned long long num)
{
	if (num >= 16)
	{
		ft_put_ptr(num / 16);
		ft_put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + 'a'), 1);
	}
}

int	ft_print_ptr(void *ptr)
{
	int	print_length;

	print_length = 0;
	if (ptr == 0)
	{
		ft_putstr("(nil)");
		print_length = 5;
	}
	else
	{
		print_length += write(1, "0x", 2);
		ft_put_ptr((unsigned long long) ptr);
		print_length += ft_ptr_len((unsigned long long) ptr);
	}
	return (print_length);
}
