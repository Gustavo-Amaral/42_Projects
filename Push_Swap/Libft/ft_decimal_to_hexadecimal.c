/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal_to_hexadecimal.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 19:13:30 by gamaral           #+#    #+#             */
/*   Updated: 2023/05/14 19:22:36 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"

// void	decimal_to_hexadecimal(int decimal_number, char *hexadecimal_string)
// {
// 	int		remainder;
// 	int		len;
// 	int		i;
// 	char	tmp;

// 	i = 0;
// 	while (decimal_number != 0)
// 	{
// 		remainder = decimal_number % 16;
// 		if (remainder < 10)
// 		{
// 			hexadecimal_string[i++] = remainder + '0';
// 		}
// 		else
// 		{
// 			hexadecimal_string[i++] = remainder + 'A' - 10;
// 		}
// 		decimal_number /= 16;
// 	}
// 	hexadecimal_string[i] = '\0';
// 	len = i;
// 	i = 0;
// 	while (i < len / 2)
// 	{
// 		tmp = hexadecimal_string[i];
// 		hexadecimal_string[i] = hexadecimal_string[len - i - 1];
// 		hexadecimal_string[len - i++ - 1] = tmp;
// 	}
// }
