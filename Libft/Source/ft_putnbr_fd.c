/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 22:37:13 by gamaral           #+#    #+#             */
/*   Updated: 2023/04/27 22:39:33 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	*c;

	if (nb == -2147483648)
	{
		ft_putchar_fd('-', fd);
		c = "2147483648";
		ft_putstr_fd(c, fd);
	}
	else
	{
		if (nb < 0)
		{
			nb = -nb;
			ft_putchar_fd('-', fd);
		}
		if (nb < 10 && nb >= 0)
		{
			ft_putchar_fd((nb + 48), fd);
		}
		else
		{
			ft_putnbr_fd((nb / 10), fd);
			ft_putchar_fd(((nb % 10) + 48), fd);
		}
	}
}
