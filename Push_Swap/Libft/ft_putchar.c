/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:56:11 by gamaral           #+#    #+#             */
/*   Updated: 2023/05/12 22:19:01 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* @summary Prints a char in the std output
* @param c The char expected for printing
* @return
*/

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
