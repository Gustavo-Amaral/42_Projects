/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2d_arrcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:57:57 by gamaral           #+#    #+#             */
/*   Updated: 2023/10/15 11:33:06 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_2d_arrcpy(void **array)
{
	unsigned char	**aux_array;
	size_t			y;
	size_t			length;

	aux_array = (unsigned char **)array;
	length = 0;
	y = 0;
	while (aux_array[y])
		y++;
	aux_array = malloc(sizeof(unsigned char *) * (y + 1));
	if (!aux_array)
		return (NULL);
	y = 0;
	while ((unsigned char)array[y])
	{
		aux_array[y] = ft_strdup(array[y]);
		y++;
	}
	aux_array[y] = NULL;
	return (aux_array);
}
