/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 22:15:30 by gamaral           #+#    #+#             */
/*   Updated: 2023/05/06 19:58:08 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	flag;
	int	aux;

	i = 0;
	flag = 0;
	aux = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			aux = i;
			flag = 1;
		}
		i++;
	}
	if (flag)
		return ((char *)s + aux);
	if (c == 0)
		return ((char *)s + i);
	return (NULL);
}
