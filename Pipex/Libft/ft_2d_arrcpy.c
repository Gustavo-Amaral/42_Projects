/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2d_arrcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:57:57 by gamaral           #+#    #+#             */
/*   Updated: 2023/11/05 17:16:55 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_2d_arrcpy(void **array)
{
	char	**aux_array;
	void	**res_array;
	size_t	y;

	aux_array = (char **)array;
	y = 0;
	while (aux_array[y])
		y++;
	res_array = malloc(sizeof(char *) * (y + 1));
	if (!aux_array)
		return (NULL);
	y = 0;
	while (aux_array[y])
	{
		res_array[y] = ft_strdup((const char *)aux_array[y]);
		y++;
	}
	res_array[y] = NULL;
	return (res_array);
}
