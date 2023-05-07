/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 22:28:54 by gamaral           #+#    #+#             */
/*   Updated: 2023/05/06 22:28:05 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				i;
	unsigned char	*aux;

	i = 0;
	aux = (unsigned char *)s;
	while (aux[i] && i < (int)n)
	{
		if (aux[i] == (unsigned char)(c))
			return ((void *)(aux + i));
		i++;
	}
	if (c == 0)
		return ((void *)(aux + i));
	return (NULL);
}
