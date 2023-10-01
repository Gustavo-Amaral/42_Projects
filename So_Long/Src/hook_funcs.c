/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 16:42:41 by gamaral           #+#    #+#             */
/*   Updated: 2023/10/01 21:37:02 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/So_long.h"

static unsigned char	is_valid_movement(t_game *game, int position, 
	char *orientation)
{
	size_t	x;
	size_t	y;

	x = game->player.position.x_position;
	y = game->player.position.y_position;
	if (ft_strcmp(orientation, HORIZONTAL) == 0)
	{
		if (game->map[y][x + position] == '1' || 
			(game->map[y][x + position] == 'E' && 
			game->items_collected != game->collectibles.total_count))
			return (FALSE);
	}
	else if (ft_strcmp(orientation, VERTICAL) == 0)
	{
		if (game->map[y + position][x] == '1' || 
			(game->map[y + position][x] == 'E' && 
			game->items_collected != game->collectibles.total_count))
			return (FALSE);
	}
	else
		return (FALSE);
	return (TRUE);
}

static void	check_collectibles(t_game *game, int x_pos, int y_pos)
{
	if (game->map[y_pos][x_pos] == 'C')
	{
		game->map[y_pos][x_pos] = '0';
		game->items_collected++;
		if (game->items_collected < game->collectibles.total_count)
			ft_printf("YOU STILL NOT DONE?!\n%d shit left, MOVE THAT ASS!\n", 
				(game->collectibles.total_count - game->items_collected));
		else if (game->items_collected == game->collectibles.total_count)
			ft_printf("FINALLY, my grandma would be faster...\nCome to me!\n");
		else
			handle_error(TOTAL_COLLECTIBLES_ERROR, game);
	}
}

static void	move_player(t_game *game, int position, char *orientation)
{
	int	x_pos;
	int	y_pos;

	if (!is_valid_movement(game, position, orientation))
		return ;
	if (ft_strcmp(orientation, HORIZONTAL) == 0)
	{
		mlx_put_image_to_window(game->mlx, game->window.window, GROUND_IMAGE,
			BLK_SIZE, BLK_SIZE);
		game->player.position.x_position += position;
		mlx_put_image_to_window(game->mlx, game->window.window, PLAYER_IMAGE,
			BLK_SIZE, BLK_SIZE);
	}
	else if (ft_strcmp(orientation, VERTICAL) == 0)
	{
		mlx_put_image_to_window(game->mlx, game->window.window, GROUND_IMAGE,
			BLK_SIZE, BLK_SIZE);
		game->player.position.y_position += position;
		mlx_put_image_to_window(game->mlx, game->window.window, PLAYER_IMAGE,
			BLK_SIZE, BLK_SIZE);
	}
	game->total_moves++;
	x_pos = game->player.position.x_position;
	y_pos = game->player.position.y_position;
	check_collectibles(game, x_pos, y_pos);
}

int	read_keys(int keypress, t_game *game)
{
	if (keypress == CAP_D || keypress == D || keypress == RIGHT)
		move_player(game, 1, HORIZONTAL);
	else if (keypress == CAP_A || keypress == A || keypress == LEFT)
		move_player(game, -1, HORIZONTAL);
	else if (keypress == CAP_S || keypress == S || keypress == DOWN)
		move_player(game, 1, VERTICAL);
	else if (keypress == CAP_W || keypress == W || keypress == UP)
		move_player(game, -1, VERTICAL);
	else if (keypress == ESC)
		end_and_free_game(game);
	return (0);
}
