/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 22:57:36 by gamaral           #+#    #+#             */
/*   Updated: 2023/04/16 23:00:36 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	i;
	int	signal;
	int	flag;
	int	result;

	signal = 1;
	i = 0;
	flag = 0;
	result = 0;
	while (nptr[i] != '\0' && flag == 0)
	{
		if ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
			i++;
		if (nptr[i] == '-')
		{
			signal *= -1;
			i++;
		}
		while (nptr[i] >= '0' && nptr[i] <= '9')
		{
			result = result * 10 + nptr[i] - '0';
			i++;
			flag = 1;
		}
		i++;
	}
	result *= signal;
	return (result);
}