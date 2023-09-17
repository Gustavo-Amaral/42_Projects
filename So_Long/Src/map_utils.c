/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:30:58 by gamaral           #+#    #+#             */
/*   Updated: 2023/09/17 20:27:03 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/So_long.h"

static unsigned char	init_characters(t_characters *character)
{
	character->img = NULL;
	character->total_count = 0;
	character->position->x_position = 0;
	character->position->y_position = 0;
}

static unsigned char	game_struct_init(t_game *game)
{
	game = malloc(sizeof(t_game));
	if (!game)
	{
		handle_error(MEMORY_ALLOCATION_FAILURE);
		return (FALSE);
	}
	game->mlx = NULL;
	game->map = NULL;
	game->window->window = NULL;
	game->window->width = 0;
	game->window->height = 0;
	init_characters(game->collectibles);
	init_characters(game->player);
	init_characters(game->exit);
	init_characters(game->wall);
	init_characters(game->ground);
	return (TRUE);
}

unsigned char	check_map_extension(char *map)
{
	char	*extension;

	extension = ft_strrchr(map, '.');
	if (ft_strcmp(extension, ".ber") != 0)
	{
		handle_error(MAP_NAME_EXTENSION_INCORRECT);
		return (FALSE);
	}
	return (TRUE);
}

char**const	read_map(char *map)
{
	char	**parsed_map;
	char	*concat_lines;
	char	*line;
	int		fildes;

	fildes = open(map, O_RDONLY);
	if (fildes < 0)
		handle_error(MAP_OPEN_FAILED);
	concat_lines = ft_strdup("");
	while (TRUE)
	{
		line = get_next_line(fildes);
		if (!line)
			break ;
		concat_lines = ft_strjoin(concat_lines, line);
		free(line);
	}
	parsed_map = ft_split(concat_lines, '\n');
	free(concat_lines);
	if (close(fildes) == -1)
		handle_error(MAP_CLOSE_FAILED);
	return (parsed_map);
}

unsigned char	check_map_validity(char *map, t_game *game)
{
	int				fildes;
	unsigned char	flag;

	fildes = open(map, __O_DIRECTORY);
	if (fildes >= 0)
	{
		handle_error(MAP_IS_A_DIRECTORY);
		return (FALSE);
	}
	flag = game_struct_init(game);
	if (!flag)
		return (FALSE);
	game->map = read_map(map);
	game->aux_map = read_map(map);
	check_map_content(game);
	return (TRUE);
}
