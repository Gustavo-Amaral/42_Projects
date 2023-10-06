/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:18:12 by gamaral           #+#    #+#             */
/*   Updated: 2023/10/06 21:47:16 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/So_long.h"

static void	init_images(t_game *game)
{
	int	blk_size;

	blk_size = BLK_SIZE;
	game->player.img = mlx_xpm_file_to_image(game->mlx, PLAYER_IMAGE, 
			&blk_size, &blk_size);
	if (!game->player.img)
		handle_error(PLAYER_IMAGE_FAILED, game);
	game->collectibles.img = mlx_xpm_file_to_image(game->mlx, COLLECT_IMAGE, 
			&blk_size, &blk_size);
	if (!game->collectibles.img)
		handle_error(COLLECT_IMAGE_FAILED, game);
	game->exit.img = mlx_xpm_file_to_image(game->mlx, PLAYER_IMAGE, 
			&blk_size, &blk_size);
	if (!game->exit.img)
		handle_error(EXIT_IMAGE_FAILED, game);
	game->wall.img = mlx_xpm_file_to_image(game->mlx, WALL_IMAGE, 
			&blk_size, &blk_size);
	if (!game->wall.img)
		handle_error(WALL_IMAGE_FAILED, game);
	game->ground.img = mlx_xpm_file_to_image(game->mlx, GROUND_IMAGE, 
			&blk_size, &blk_size);
	if (!game->ground.img)
		handle_error(GROUND_IMAGE_FAILED, game);
	printf("init images\n");
}

static void	load_img_to_window(char character, t_game *game, int x, int y)
{
	printf("load images\n");
	if (character == '0')
		mlx_put_image_to_window(game->mlx, game->window.window, 
			game->ground.img, x * BLK_SIZE, y * BLK_SIZE);
	if (character == '1')
		mlx_put_image_to_window(game->mlx, game->window.window, 
			game->wall.img, x * BLK_SIZE, y * BLK_SIZE);
	if (character == 'P')
		mlx_put_image_to_window(game->mlx, game->window.window, 
			game->player.img, x * BLK_SIZE, y * BLK_SIZE);
	if (character == 'C')
		mlx_put_image_to_window(game->mlx, game->window.window, 
			game->collectibles.img, x * BLK_SIZE, y * BLK_SIZE);
	if (character == 'E')
		mlx_put_image_to_window(game->mlx, game->window.window, 
			game->exit.img, x * BLK_SIZE, y * BLK_SIZE);
}

static void	load_images(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			load_img_to_window(game->map[y][x], game, x, y);
			x++;
		}
		y++;
	}
}

void	setting_window_size(t_game *game)
{
	int	x_length;
	int	y_length;

	x_length = ft_strlen(game->map[0]);
	y_length = 0;
	while (game->map[y_length])
		y_length++;
	game->window.width = x_length;
	game->window.height = y_length;
}

unsigned char	render_game(t_game *game)
{
	printf("render game\n");
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		handle_error(FAILED_TO_RENDER, game);
		return (FALSE);
	}
	game->window.window = mlx_new_window(game->mlx, 
			game->window.width * BLK_SIZE, game->window.height * BLK_SIZE, 
			"SO_LONG GUSTAVO AMARAL");
	if (!game->window.window)
	{
		handle_error(FAILED_TO_CREATE_WINDOW, game);
		return (FALSE);
	}
	init_images(game);
	load_images(game);
	printf("passou do load images\n");
	mlx_key_hook(game->window.window, read_keys, game);
	mlx_hook(game->window.window, 17, 1L << 0, end_and_free_game, game);
	mlx_loop(game->mlx);
	return (TRUE);
}
