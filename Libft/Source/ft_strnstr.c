/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 22:41:08 by gamaral           #+#    #+#             */
/*   Updated: 2023/04/17 22:29:51 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i;
	int	flag;

	if (!little)
		return (big);
	while (big)
	{
		if (*big == *little)
		{
			i = 0;
			flag = 0;
			while (little[i] != '\0')
			{
				if (big[i] != little[i])
					flag = 1;
				i++;
			}
			if (flag == 0)
				return (big);
		}
		big++;
	}
	return (0);
}