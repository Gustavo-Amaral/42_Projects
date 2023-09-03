/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 22:50:57 by gamaral           #+#    #+#             */
/*   Updated: 2023/09/03 18:45:20 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

bool	check_size(t_vector2D iter, t_vector2D size, char **map, int *err_code)
{
	if (iter.y == 0 || iter.y == size.y - 1)
	{
		if (map[iter.y][iter.x] != '1')
		{
			*err_code = INVALID_WALLS_IN_MAP;
			return (FALSE);
		}
	}
	if (iter.x == 0 || iter.x == size.x - 1)
	{
		if (map[iter.y][iter.x] != '1')
		{
			*err_code = INVALID_WALLS_IN_MAP;
			return (FALSE);
		}
	}
	return (TRUE);
}

char	**several_start_selecting(char **map, int p_count, t_vars *vars)
{
	int	count;
	int	rand;
	int	i;
	int	j;

	rand = random_nb(vars) % p_count;
	count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (count != rand && map[i][j] == 'P')
			{
				count++;
				map[i][j] = '0';
			}
			if (map[i][j] == 'P')
				count++;
			j++;
		}
		i++;
	}
	return (map);
}
