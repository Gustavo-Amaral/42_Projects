/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:30:58 by gamaral           #+#    #+#             */
/*   Updated: 2023/10/15 11:38:44 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/So_long.h"

static void	init_characters(t_characters character)
{
	character.img = NULL;
	character.total_count = 0;
	character.position.x_position = 0;
	character.position.y_position = 0;
}

t_game	*game_struct_init(t_game *game)
{
	game = malloc(sizeof(t_game) * 1);
	if (!game)
	{
		handle_error(MEMORY_ALLOCATION_FAILURE, NULL);
		return (FALSE);
	}
	game->mlx = NULL;
	game->map = NULL;
	game->aux_map = NULL;
	game->window.window = NULL;
	game->window.width = 0;
	game->window.height = 0;
	game->items_collected = 0;
	game->total_moves = 0;
	init_characters(game->collectibles);
	init_characters(game->player);
	init_characters(game->exit);
	init_characters(game->wall);
	init_characters(game->ground);
	return (game);
}

unsigned char	check_map_extension(char *map)
{
	char	*extension;

	extension = ft_strrchr(map, '.');
	if (ft_strcmp(extension, ".ber") != 0)
	{
		handle_error(MAP_NAME_EXTENSION_INCORRECT, NULL);
		return (FALSE);
	}
	return (TRUE);
}

char	**read_map(char *map, t_game *game)
{
	char	**parsed_map;
	char	*concat_lines;
	char	*line;
	char	*aux;
	int		fildes;

	fildes = open(map, O_RDONLY);
	if (fildes < 0)
		handle_error(MAP_OPEN_FAILED, game);
	concat_lines = ft_strdup("");
	while (TRUE)
	{
		aux = concat_lines;
		line = get_next_line(fildes);
		if (!line)
			break ;
		concat_lines = ft_strjoin(concat_lines, line);
		free(aux);
		free(line);
	}
	parsed_map = ft_split(concat_lines, '\n');
	free(concat_lines);
	if (close(fildes) == -1)
		handle_error(MAP_CLOSE_FAILED, game);
	return (parsed_map);
}

unsigned char	check_map_validity(char *map, t_game *game)
{
	int				fildes;

	fildes = open(map, __O_DIRECTORY);
	if (fildes >= 0)
	{
		handle_error(MAP_IS_A_DIRECTORY, NULL);
		return (FALSE);
	}
	if (!game)
		return (FALSE);
	game->map = read_map(map, game);
	game->aux_map = read_map(map, game);
	check_map_content(game);
	return (TRUE);
}
