/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:30:58 by gamaral           #+#    #+#             */
/*   Updated: 2023/10/06 20:01:06 by gamaral          ###   ########.fr       */
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
	printf("init\n");
	game = malloc(sizeof(t_game) * 1);
	if (!game)
	{
		handle_error(MEMORY_ALLOCATION_FAILURE, NULL);
		return (FALSE);
	}
	printf("pos malloc\n");
	game->mlx = NULL;
	game->map = NULL;
	game->aux_map = NULL;
	game->window.window = NULL;
	game->window.width = 0;
	game->window.height = 0;
	game->items_collected = 0;
	game->total_moves = 0;
	printf("init characters\n");
	init_characters(game->collectibles);
	printf("init characters 2\n");
	init_characters(game->player);
	init_characters(game->exit);
	init_characters(game->wall);
	init_characters(game->ground);
	printf("init feito\n");
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
	int		fildes;

	printf("opening\n");
	fildes = open(map, O_RDONLY);
	if (fildes < 0)
		handle_error(MAP_OPEN_FAILED, game);
	concat_lines = ft_strdup("");
	printf("while\n");
	while (TRUE)
	{
		line = get_next_line(fildes);
		if (!line)
			break ;
		concat_lines = ft_strjoin(concat_lines, line);
		free(line);
	}
	parsed_map = ft_split(concat_lines, '\n');
	printf("split\n");
	free(concat_lines);
	printf("concat_lines\n");
	if (close(fildes) == -1)
		handle_error(MAP_CLOSE_FAILED, game);
	printf("returning\n");
	printf("line: %s\nUltima linha: %s\n", parsed_map[2], parsed_map[10]);
	return (parsed_map);
}

unsigned char	check_map_validity(char *map, t_game *game)
{
	int				fildes;
	char			**aux;

	fildes = open(map, __O_DIRECTORY);
	if (fildes >= 0)
	{
		handle_error(MAP_IS_A_DIRECTORY, NULL);
		return (FALSE);
	}
	if (!game)
		return (FALSE);
	printf("lendo mapa\n");
	game->map = read_map(map, game);
	printf("string: %s\n", game->map[1]);
	game->aux_map = read_map(map, game);
	check_map_content(game);
	return (TRUE);
}
