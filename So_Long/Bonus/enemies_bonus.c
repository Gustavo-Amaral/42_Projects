/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:56:04 by gamaral           #+#    #+#             */
/*   Updated: 2023/10/08 22:06:45 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"

static int count_map_zeros(t_game *game)
{
	int	x;
	int	y;
	int counter;

	y = 0;
	counter = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '0')
				counter++;
			x++;
		}
		y++;
	}
	return (counter);
}

static void	get_map_dimensions(t_game *game, int *height, int *width)
{
	int	y;

	y = 0;
	*width = ft_strlen(game->map[y]);
	while (game->map[y])
		y++;
	*height = y;
}

static void	random_place_enemy(t_game *game, char **map, int max_height, int max_width)
{
	int	y;
	int	x;

	while (TRUE)
	{
		y = rand() % max_height;
		x = rand() % max_width;
		if (x > 0 && x < (max_width - 1) && y > 0 && y < (max_height - 1))
		{
			if (map[y][x] == '0')
			{
				map[y][x] == 'F';
				game->enemies.position.x_position = x;
				game->enemies.position.y_position = y;
				return ;
			}
		}
	}
}

static void place_enemies_in_map(t_game *game)
{
	int		enemy_number;
	int		width;
	int		height;

	//enemy_number = count_map_zeros(game) % 10;
	enemy_number = 1;
	get_map_dimensions(game, &height, &width);
	while(enemy_number > 0)
	{
		random_place_enemy(game, game->map, height, width);
		enemy_number--;
	}
}

int	render_enemies(t_game *game)
{
	int	blk_size;

	blk_size = BLK_SIZE;
	game->enemies.img = mlx_xpm_file_to_image(game->mlx, ENEMY_IMAGE, 
			&blk_size, &blk_size);
	if (!game->player.img)
		handle_error(ENEMY_IMAGE_FAILED, game);
	place_enemies_in_map(game);
	return (TRUE);
}