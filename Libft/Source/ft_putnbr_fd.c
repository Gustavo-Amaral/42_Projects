/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 22:37:13 by gamaral           #+#    #+#             */
/*   Updated: 2023/05/06 22:39:36 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	*c;

	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		c = "2147483648";
		ft_putstr_fd(c, fd);
	}
	else
	{
		if (n < 0)
		{
			n = -n;
			ft_putchar_fd('-', fd);
		}
		if (n < 10 && n >= 0)
		{
			ft_putchar_fd((n + 48), fd);
		}
		else
		{
			ft_putnbr_fd((n / 10), fd);
			ft_putchar_fd(((n % 10) + 48), fd);
		}
	}
}
