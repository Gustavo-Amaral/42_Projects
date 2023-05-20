/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 22:17:56 by gamaral           #+#    #+#             */
/*   Updated: 2023/05/06 20:00:42 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*aux;
	size_t	i;
	size_t	j;

	aux = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!aux)
		return (NULL);
	i = 0;
	j = 0;
	while (i < ft_strlen(s1))
	{
		aux[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2))
	{
		aux[i] = s2[j];
		i++;
		j++;
	}
	aux[i] = '\0';
	return (aux);
}
