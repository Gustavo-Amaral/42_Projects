/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 21:02:19 by gamaral           #+#    #+#             */
/*   Updated: 2023/10/22 15:29:31 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/So_long.h"

static unsigned char	check_map_rectangular(char **map)
{
	int	length;
	int	x;
	int	y;

	length = ft_strlen(map[0]);
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
			x++;
		if (x != length)
			return (FALSE);
		y++;
	}
	return (TRUE);
}

static unsigned char	check_map_borders(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (y == 0 || map[y + 1] == NULL)
				if (map[y][x] != '1')
					return (FALSE);
			if (x == 0 || map[y][x + 1] == '\n')
				if (map[y][x] != '1')
					return (FALSE);
			x++;
		}
		y++;
	}
	return (TRUE);
}

static unsigned char	check_character(char character,
	t_game *game, int y, int x)
{
	static int	exit_count;
	static int	player_count;
	static int	collectible_count;

	if (character != 'E' && character != 'P' && character != 'C' && character != '0' && character != '1')
		return (FALSE);
	if (character == 'E')
	{
		exit_count++;
		game->exit.total_count = exit_count;
	}
	if (character == 'P')
	{
		player_count++;
		game->player.total_count = player_count;
		game->player.position.x_position = x;
		game->player.position.y_position = y;
	}
	if (character == 'C')
	{
		collectible_count++;
		game->collectibles.total_count = collectible_count;
	}
	return (TRUE);
}

static unsigned char	check_map_characters(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (!check_character(game->map[y][x], game, y, x))
				return (FALSE);
			x++;
		}
		y++;
	}
	if (game->collectibles.total_count < 1 || game->exit.total_count != 1 || game->player.total_count != 1)
		return (FALSE);
	return (TRUE);
}

unsigned char	check_map_content(t_game *game)
{
	if (!check_map_rectangular(game->map))
	{
		handle_error(MAP_NOT_RECTANGULAR, game);
		return (FALSE);
	}
	if (!check_map_borders(game->map))
	{
		handle_error(INVALID_WALLS_IN_MAP, game);
		return (FALSE);
	}
	if (!check_map_characters(game))
	{
		handle_error(INVALID_CHARS_IN_MAP, game);
		return (FALSE);
	}
	if (!check_valid_path(game))
	{
		handle_error(INVALID_PATH_IN_MAP, game);
		return (FALSE);
	}
	return (TRUE);
}
