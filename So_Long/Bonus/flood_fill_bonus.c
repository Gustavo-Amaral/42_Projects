/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 17:14:26 by gamaral           #+#    #+#             */
/*   Updated: 2023/10/22 15:39:01 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long_bonus.h"

static void	fill_path(char **map, int x, int y, t_window window)
{
	if (y < 0 || x < 0 || y >= window.height || x >= window.width)
		return ;
	if (map[y][x] != '0' && map[y][x] != 'P' && map[y][x] != 'C' && map[y][x] != 'E')
		return ;
	map[y][x] = 'X';
	fill_path(map, x + 1, y, window);
	fill_path(map, x - 1, y, window);
	fill_path(map, x, y + 1, window);
	fill_path(map, x, y - 1, window);
}

unsigned char	check_valid_path(t_game *game)
{
	int			y;
	int			x;

	y = 0;
	x = 0;
	setting_window_size(game);
	fill_path(game->aux_map, game->player.position.x_position, game->player.position.y_position, game->window);
	while (game->aux_map[y])
	{
		while (game->aux_map[y][x])
		{
			if (game->aux_map[y][x] == 'C' || game->aux_map[y][x] == 'P' || game->aux_map[y][x] == 'E')
				return (FALSE);
			x++;
		}
		y++;
		x = 0;
	}
	return (TRUE);
}
