/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_funcs_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:35:58 by gamaral           #+#    #+#             */
/*   Updated: 2023/10/22 15:40:51 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long_bonus.h"

static unsigned char	is_valid_movement(t_game *game, int position, char *orientation)
{
	size_t	x;
	size_t	y;

	x = game->player.position.x_position;
	y = game->player.position.y_position;
	if (ft_strcmp(orientation, HORIZONTAL) == 0)
	{
		if (game->map[y][x + position] == '1' || (game->map[y][x + position] == 'E' && game->items_collected != game->collectibles.total_count))
			return (FALSE);
		else if (game->map[y][x + position] == 'E')
			end_and_free_game(game);
	}
	else if (ft_strcmp(orientation, VERTICAL) == 0)
	{
		if (game->map[y + position][x] == '1' || (game->map[y + position][x] == 'E' && game->items_collected != game->collectibles.total_count))
			return (FALSE);
		else if (game->map[y + position][x] == 'E')
			end_and_free_game(game);
	}
	return (TRUE);
}

static void	check_collectibles(t_game *game, int x_pos, int y_pos)
{
	if (game->map[y_pos][x_pos] == 'C')
	{
		game->map[y_pos][x_pos] = '0';
		game->items_collected++;
		if (game->items_collected < game->collectibles.total_count)
		{
			ft_printf("\nMagic Portal: YOU STILL NOT DONE?!\n");
			ft_printf("Magic Portal: %d fire shit left, MOVE THAT ASS!\n\n",
				(game->collectibles.total_count - game->items_collected));
		}
		else if (game->items_collected == game->collectibles.total_count)
		{
			ft_printf("\nMagic Portal: FINALLY, grandma would be faster!\n");
			ft_printf("Magic Portal: Leave this shitty game for good!\n\n");
		}
		else
			handle_error(TOTAL_COLLECTIBLES_ERROR, game);
	}
}

static void	move_player_x(t_game *game, int position, char *orientation)
{
	int	x_pos;
	int	y_pos;

	x_pos = game->player.position.x_position;
	y_pos = game->player.position.y_position;
	if (!is_valid_movement(game, position, orientation))
		return ;
	if (ft_strcmp(orientation, HORIZONTAL) == 0)
	{
		mlx_put_image_to_window(game->mlx, game->window.window, game->ground.img, x_pos * BLK_SIZE, y_pos * BLK_SIZE);
		game->player.position.x_position += position;
		mlx_put_image_to_window(game->mlx, game->window.window, game->player.img, (x_pos + position) * BLK_SIZE, y_pos * BLK_SIZE);
	}
	else
		return ;
	game->total_moves++;
	ft_print_movements(game);
	ft_printf("Magic Portal: %d moves already... Couldn't you do it better?!\n", game->total_moves);
	check_collectibles(game, game->player.position.x_position, game->player.position.y_position);
	check_player_colision(game);
}

static void	move_player_y(t_game *game, int position, char *orientation)
{
	int	x_pos;
	int	y_pos;

	x_pos = game->player.position.x_position;
	y_pos = game->player.position.y_position;
	if (!is_valid_movement(game, position, orientation))
		return ;
	if (ft_strcmp(orientation, VERTICAL) == 0)
	{
		mlx_put_image_to_window(game->mlx, game->window.window, game->ground.img, x_pos * BLK_SIZE, y_pos * BLK_SIZE);
		game->player.position.y_position += position;
		mlx_put_image_to_window(game->mlx, game->window.window, game->player.img, x_pos * BLK_SIZE, (y_pos + position) * BLK_SIZE);
	}
	else
		return ;
	game->total_moves++;
	ft_print_movements(game);
	ft_printf("Magic Portal: %d moves already... Couldn't you do it better?!\n", game->total_moves);
	check_collectibles(game, game->player.position.x_position, game->player.position.y_position);
	check_player_colision(game);
}

// static void	move_player(t_game *game, int position, char *orientation)
// {
// 	int	x_pos;
// 	int	y_pos;

// 	x_pos = game->player.position.x_position;
// 	y_pos = game->player.position.y_position;
// 	if (!is_valid_movement(game, position, orientation))
// 		return ;
// 	if (ft_strcmp(orientation, HORIZONTAL) == 0)
// 	{
// 		mlx_put_image_to_window(game->mlx, game->window.window, 
// 			game->ground.img, x_pos * BLK_SIZE, y_pos * BLK_SIZE);
// 		game->player.position.x_position += position;
// 		mlx_put_image_to_window(game->mlx, game->window.window, 
// 			game->player.img, (x_pos + position) * BLK_SIZE, y_pos * BLK_SIZE);
// 	}
// 	else if (ft_strcmp(orientation, VERTICAL) == 0)
// 	{
// 		mlx_put_image_to_window(game->mlx, game->window.window, 
// 			game->ground.img, x_pos * BLK_SIZE, y_pos * BLK_SIZE);
// 		game->player.position.y_position += position;
// 		mlx_put_image_to_window(game->mlx, game->window.window, 
// 			game->player.img, x_pos * BLK_SIZE, (y_pos + position) * BLK_SIZE);
// 	}
// 	game->total_moves++;
// 	check_collectibles(game, game->player.position.x_position, 
//		game->player.position.y_position);
// }

int	read_keys(int keypress, t_game *game)
{
	if (keypress == CAP_D || keypress == D || keypress == RIGHT)
	{
		move_player_x(game, 1, HORIZONTAL);
		mirror_enemy_move_x(game, -1, HORIZONTAL);
	}
	else if (keypress == CAP_A || keypress == A || keypress == LEFT)
	{
		move_player_x(game, -1, HORIZONTAL);
		mirror_enemy_move_x(game, 1, HORIZONTAL);
	}
	else if (keypress == CAP_S || keypress == S || keypress == DOWN)
	{
		move_player_y(game, 1, VERTICAL);
		mirror_enemy_move_y(game, -1, VERTICAL);
	}
	else if (keypress == CAP_W || keypress == W || keypress == UP)
	{
		move_player_y(game, -1, VERTICAL);
		mirror_enemy_move_y(game, 1, VERTICAL);
	}
	else if (keypress == ESC)
		end_and_free_game(game);
	return (0);
}
