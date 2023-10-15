/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:34:47 by gamaral           #+#    #+#             */
/*   Updated: 2023/10/15 11:33:51 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long_bonus.h"

void	ft_print_movements(t_game *game)
{
	char	*movements;
	char	*phrase;

	movements = ft_itoa(game->total_moves);
	phrase = ft_strjoin("Magic Portal: ", movements);
	mlx_string_put(game->mlx, game->window.window, 40, 20, 99999, phrase);
	free(movements);
	free(phrase);
}

void	handle_error(char *error, t_game *game)
{
	ft_putstr_fd("\nError\n", STDERR_FILENO);
	ft_putstr_fd(error, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	end_and_free_game(game);
}

static void	destroy_imgs(t_game *game)
{
	if (game->collectibles.img)
		mlx_destroy_image(game->mlx, game->collectibles.img);
	if (game->player.img)
		mlx_destroy_image(game->mlx, game->player.img);
	if (game->wall.img)
		mlx_destroy_image(game->mlx, game->wall.img);
	if (game->ground.img)
		mlx_destroy_image(game->mlx, game->ground.img);
	if (game->exit.img)
		mlx_destroy_image(game->mlx, game->exit.img);
	if (game->enemies.img)
		mlx_destroy_image(game->mlx, game->enemies.img);
}

static void	free_map(char **map)
{
	size_t	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
	map = NULL;
}

int	end_and_free_game(t_game *game)
{
	if (!game)
		exit(EXIT_SUCCESS);
	destroy_imgs(game);
	if (game->window.window)
		mlx_destroy_window(game->mlx, game->window.window);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (game->map)
		free_map(game->map);
	if (game->aux_map)
		free_map(game->aux_map);
	free(game);
	game = NULL;
	exit(EXIT_SUCCESS);
	return (TRUE);
}
