/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:16:39 by gamaral           #+#    #+#             */
/*   Updated: 2023/02/13 23:43:50 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putchar(char c)
{
	write(1, &c, 1);
}

void	putminstr(void)
{
	char	*c;

	c = "2147483648";
	while (*c != '\0')
	{
		write(1, c, 1);
		c++;
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		putchar('-');
		putminstr();
	}
	else
	{
		if (nb < 0)
		{
			nb = -nb;
			putchar('-');
		}
		if (nb < 10 && nb >= 0)
		{
			putchar(nb + 48);
		}
		else
		{
			ft_putnbr(nb / 10);
			putchar((nb % 10) + 48);
		}
	}
}
