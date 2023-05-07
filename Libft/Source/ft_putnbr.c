/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:16:39 by gamaral           #+#    #+#             */
/*   Updated: 2023/05/06 19:58:08 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	char	*c;

	if (nb == -2147483648)
	{
		ft_putchar('-');
		c = "2147483648";
		ft_putstr(c);
	}
	else
	{
		if (nb < 0)
		{
			nb = -nb;
			ft_putchar('-');
		}
		if (nb < 10 && nb >= 0)
		{
			ft_putchar(nb + 48);
		}
		else
		{
			ft_putnbr(nb / 10);
			ft_putchar((nb % 10) + 48);
		}
	}
}
