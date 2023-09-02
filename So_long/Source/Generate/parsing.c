/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 20:30:39 by gamaral           #+#    #+#             */
/*   Updated: 2023/09/02 22:54:05 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

static void	check_char_count(char block, int *player_count, int *items_count, int *exits_count)
{
	if (block == 'P')
		*player_count++;
	if (block == 'C')
		*items_count++;
	if (block == 'E')
		*exits_count++;
}

static int is_valid_char_map(char **map, int *items_count, int *fildes_or_error)
{
	t_vector2D	iter;
	int			player_count;
	int			exits_count;

	iter.y = 0;
	player_count = 0;
	exits_count = 0;
	while (map[iter.y])
	{
		while (map[iter.y][iter.x])
		{
			if(map[iter.y][iter.x] != 'P' && map[iter.y][iter.x] != 'C'
				&& map[iter.y][iter.x] != 'E' && map[iter.y][iter.x] != '1'
					&& map[iter.y][iter.x] != '0')
				return (INVALID_CHARS_IN_MAP);
			check_char_count(map[iter.y][iter.x], &player_count, items_count, &exits_count);
			iter.x++;
		}
		iter.y++;
	}
	if (exits_count != 1 || *items_count == 0 || player_count != 1)
		return (INVALID_CHARS_IN_MAP);
	return (player_count);
}

statis bool is_valid_size_map(char **map, t_vector2D *size, int *error_code)
{
	t_vector2D	iter;
	int			line_size;

	iter.y = 0;
	iter.x = 0;
	line_size = 0;
	while (map[iter.y])
	{
		iter.x = 0;
		while (map[iter.y][iter.x])
			iter.x++;
		if (iter.y == 0)
			line_size = iter.x;
		else if (iter.x != line_size)
		{
			*error_code = MAP_NOT_RECTANGULAR;
			return (FALSE);
		}
		iter.y++;
	}
	(*size).x = line_size;
	(*size).y = iter.y;
	return (TRUE);
}
statis bool is_valid_wall_map(char **map, t_vector2D size, int *error_code)
{
	t_vector2D	iter;

	iter.y = 0;
	iter.x = 0;

	while (map[iter.y])
	{
		iter.x = 0;
		while (map[iter.y][iter.x])
		{
			if (!check_size(iter, size, map, error_code))
				return (FALSE);
			iter.x++;
		}
		iter.y++;
	}
	return (TRUE);
}

char    **read_map(int *fildes_or_error, t_vector2D *size, int *items, t_vars *vars)
{
    char    *buf;
    char    **map;
    int		player_count;

	if (*fildes_or_error < 1)
		return (NULL);
	buf = read_file(*fildes_or_error, &vars->lst);
	if (!buf)
		return (NULL);
	map = ft_split(buf, '\n');
	if (!map)
		return (NULL);
	player_count = is_valid_char_map(map, items, fildes_or_error);
	if (player_count < 0 || !is_valid_size_map(map, size, fildes_or_error)
			|| !is_valid_wall_map(map, *size, fildes_or_error))
	{
		if (player_count < 0)
			*fildes_or_error = player_count
		return (NULL);
	}
	if (player_count == 1)
		several_start_selecting(map, player_count, vars);
	return (map);
}