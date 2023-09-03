/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 20:30:39 by gamaral           #+#    #+#             */
/*   Updated: 2023/09/03 18:18:44 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

static void	char_count(char block, int *p_count, int *c_count, int *e_count)
{
	if (block == 'P')
		*p_count++;
	if (block == 'C')
		*c_count++;
	if (block == 'E')
		*e_count++;
}

static int	is_valid_char_map(char **map, int *c_count, int *fildes_or_error)
{
	t_vector2D	iter;
	int			p_count;
	int			e_count;

	iter.y = 0;
	p_count = 0;
	e_count = 0;
	while (map[iter.y])
	{
		while (map[iter.y][iter.x])
		{
			if (map[iter.y][iter.x] != 'P' && map[iter.y][iter.x] != 'C'
				&& map[iter.y][iter.x] != 'E' && map[iter.y][iter.x] != '1'
					&& map[iter.y][iter.x] != '0')
				return (INVALID_CHARS_IN_MAP);
			char_count(map[iter.y][iter.x], &p_count, c_count, &e_count);
			iter.x++;
		}
		iter.y++;
	}
	if (e_count != 1 || *c_count == 0 || p_count != 1)
		return (INVALID_CHARS_IN_MAP);
	return (p_count);
}

static bool	is_valid_size_map(char **map, t_vector2D *size, int *error_code)
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

static bool	is_valid_wall_map(char **map, t_vector2D size, int *error_code)
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

char	**read_map(int *fd_or_error, t_vector2D *size, int *items, t_vars *vars)
{
	char	*buf;
	char	**map;
	int		p_count;

	if (*fd_or_error < 1)
		return (NULL);
	buf = read_file(*fd_or_error, &vars->lst);
	if (!buf)
		return (NULL);
	map = ft_split(buf, '\n');
	if (!map)
		return (NULL);
	p_count = is_valid_char_map(map, items, fd_or_error);
	if (p_count < 0 || !is_valid_size_map(map, size, fd_or_error)
		|| !is_valid_wall_map(map, *size, fd_or_error))
	{
		if (p_count < 0)
			*fd_or_error = p_count;
		return (NULL);
	}
	return (map);
}

	/* 
	** CODE USED FOR MULTIPLE POSSIBLE PLAYER STARTING POSITION 
	** CODE POSITION IS RIGHT BEFORE LAST RETURN ON read_map FUNCTION
	** ADJUSTMENTS ARE NEEDED IN LAST IF IN "is_valid_char_map" FUNCTION
	*/
	/* if (p_count > 1)
		several_start_selecting(map, player_count, vars); */