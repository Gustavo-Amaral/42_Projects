/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 22:50:57 by gamaral           #+#    #+#             */
/*   Updated: 2023/09/02 22:56:45 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

bool check_size(t_vector2D iter, t_vector2D size, char **map, int *error_code)
{
	if (iter.y == 0 || iter.y == size.y - 1)
	{
		if (map[iter.y][iter.x] != '1')
		{
			*error_code = INVALID_WALLS_IN_MAP;
			return (FALSE);
		}
	}
	if (iter.x == 0 || iter.x == size.x - 1)
	{
		if (map[iter.y][iter.x] != '1')
		{
			*error_code = INVALID_WALLS_IN_MAP;
			return (FALSE);
		}
	}
	return (TRUE);
}