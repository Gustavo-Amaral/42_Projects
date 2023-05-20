/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 19:15:56 by gamaral           #+#    #+#             */
/*   Updated: 2023/05/20 23:00:20 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_str(char *c)
{
	int	print_length;

	if (c == NULL)
	{
		ft_putstr("(null)");
		print_length = 6;
	}
	else
	{
		print_length = ft_strlen(c);
		ft_putstr(c);
	}
	return (print_length);
}
