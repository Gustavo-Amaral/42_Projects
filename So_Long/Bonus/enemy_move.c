/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 21:55:59 by gamaral           #+#    #+#             */
/*   Updated: 2023/10/22 15:38:33 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long_bonus.h"

static unsigned char	is_valid_enemy_movement(t_game *game, int position, char *orientation)
{
	size_t	x;
	size_t	y;

	x = game->enemies.position.x_position;
	y = game->enemies.position.y_position;
	if (ft_strcmp(orientation, HORIZONTAL) == 0)
	{
		if (game->map[y][x + position] == '1' || (game->map[y][x + position] == 'E' || game->map[y][x + position] == 'C'))
			return (FALSE);
	}
	else if (ft_strcmp(orientation, VERTICAL) == 0)
	{
		if (game->map[y + position][x] == '1' || (game->map[y + position][x] == 'E' || game->map[y + position][x] == 'C'))
			return (FALSE);
	}
	return (TRUE);
}

void	mirror_enemy_move_x(t_game *game, int position, char *orientation)
{
	int	x_pos;
	int	y_pos;

	x_pos = game->enemies.position.x_position;
	y_pos = game->enemies.position.y_position;
	if (!is_valid_enemy_movement(game, position, orientation))
		return ;
	if (ft_strcmp(orientation, HORIZONTAL) == 0)
	{
		mlx_put_image_to_window(game->mlx, game->window.window, game->ground.img, x_pos * BLK_SIZE, y_pos * BLK_SIZE);
		game->enemies.position.x_position += position;
		mlx_put_image_to_window(game->mlx, game->window.window, game->enemies.img, (x_pos + position) * BLK_SIZE, y_pos * BLK_SIZE);
	}
	else
		return ;
	check_player_colision(game);
}

void	mirror_enemy_move_y(t_game *game, int position, char *orientation)
{
	int	x_pos;
	int	y_pos;

	x_pos = game->enemies.position.x_position;
	y_pos = game->enemies.position.y_position;
	if (!is_valid_enemy_movement(game, position, orientation))
		return ;
	if (ft_strcmp(orientation, VERTICAL) == 0)
	{
		mlx_put_image_to_window(game->mlx, game->window.window, game->ground.img, x_pos * BLK_SIZE, y_pos * BLK_SIZE);
		game->enemies.position.y_position += position;
		mlx_put_image_to_window(game->mlx, game->window.window, game->enemies.img, x_pos * BLK_SIZE, (y_pos + position) * BLK_SIZE);
	}
	else
		return ;
	check_player_colision(game);
}

void	check_player_colision(t_game *game)
{
	if (game->player.position.x_position == game->enemies.position.x_position && game->player.position.y_position == game->enemies.position.y_position)
	{
		ft_printf("\nMagic Portal: WHAT?!?!?!\nHOW THE HECK YOU GOT HIT BY THE ENEMY?!");
		ft_printf("\nARE YOU BLIND?!\nJEEEEZ!!!\n\n");
		end_and_free_game(game);
	}
}
