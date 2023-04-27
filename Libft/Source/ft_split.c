/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:47:28 by gamaral           #+#    #+#             */
/*   Updated: 2023/04/27 22:32:09 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*allocate(char *str, int i)
{
	char	*aux;

	aux = malloc(ft_strlen(str) * sizeof(char) + 1);
	if (!aux)
		return (NULL)
	while (str[i])
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	char	*aux;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ft_bzero(aux, ft_strlen(s));
	while(s[i])
	{
		if (s[i] == c)
		{
			ft_strcpy(str[j++], aux);
			ft_bzero(aux, ft_strlen(s));
		}
		else
			aux[i] = s[i];
		i++;
	}
}