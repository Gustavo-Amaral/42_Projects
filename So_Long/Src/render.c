/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:18:12 by gamaral           #+#    #+#             */
/*   Updated: 2023/09/17 20:46:24 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/So_long.h"

static void	init_images(t_game *game)
{
	int	blk_size;
	int	*blk;

	blk_size = BLK_SIZE;
	blk = &blk_size;
	game->player->img = mlx_xpm_file_to_image(game->mlx, PLAYER_IMAGE, 
			blk, blk);
	if (!game->player->img)
		handle_error(PLAYER_IMAGE_FAILED);
	game->collectibles->img = mlx_xpm_file_to_image(game->mlx, COLLECT_IMAGE, 
			blk, blk);
	if (!game->collectibles->img)
		handle_error(COLLECT_IMAGE_FAILED);
	game->exit->img = mlx_xpm_file_to_image(game->mlx, EXIT_IMAGE, 
			blk, blk);
	if (!game->exit->img)
		handle_error(EXIT_IMAGE_FAILED);
	game->wall->img = mlx_xpm_file_to_image(game->mlx, WALL_IMAGE, 
			blk, blk);
	if (!game->wall->img)
		handle_error(WALL_IMAGE_FAILED);
	game->ground->img = mlx_xpm_file_to_image(game->mlx, GROUND_IMAGE, 
			blk, blk);
	if (!game->ground->img)
		handle_error(GROUND_IMAGE_FAILED);
}

static void	load_img_to_window(char character, t_game *game)
{
	if (character == '0')
		mlx_put_image_to_window(game->mlx, game->window->window, 
			game->ground->img, BLK_SIZE, BLK_SIZE);
	if (character == '1')
		mlx_put_image_to_window(game->mlx, game->window->window, 
			game->wall->img, BLK_SIZE, BLK_SIZE);
	if (character == 'P')
		mlx_put_image_to_window(game->mlx, game->window->window, 
			game->player->img, BLK_SIZE, BLK_SIZE);
	if (character == 'C')
		mlx_put_image_to_window(game->mlx, game->window->window, 
			game->collectibles->img, BLK_SIZE, BLK_SIZE);
	if (character == 'E')
		mlx_put_image_to_window(game->mlx, game->window->window, 
			game->exit->img, BLK_SIZE, BLK_SIZE);
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
			load_img_to_window(game->map[y][x], game);
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
	game->window->width = x_length;
	game->window->height = y_length;
}

unsigned char	render_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		handle_error(FAILED_TO_RENDER);
		return (FALSE);
	}
	game->window->window = mlx_new_window(game->mlx, 
			game->window->width * BLK_SIZE, game->window->height * BLK_SIZE, 
			"SO_LONG GUSTAVO AMARAL");
	if (!game->window->window)
	{
		handle_error(FAILED_TO_CREATE_WINDOW);
		return (FALSE);
	}
	init_images(game);
	load_images(game);
	return (TRUE);
}
