/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   So_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:53:57 by gamaral           #+#    #+#             */
/*   Updated: 2023/09/17 20:33:31 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../Libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"

/* BOOLEAN DEFINITIONS */

# define FALSE          0
# define TRUE           1

/* STD DEFINITIONS */

# define STDIN_FILENO	0
# define STDOUT_FILENO	1
# define STDERR_FILENO	2

/* WINDOW DEFINITIONS */

# define BLK_SIZE		40

/* MAP RELATED ERRORS */

# define MAP_NAME_CORRECT               0
# define MAP_NOT_RECTANGULAR            "Map is not rectangular!"
# define MAP_NAME_EXTENSION_INCORRECT   "Map's name extension is incorrect!"
# define MAP_IS_A_DIRECTORY				"Map is a directory!"
# define MAP_OPEN_FAILED				"Failed to open map!\nDoes it exist?"
# define MAP_CLOSE_FAILED				"Failed to close map!"
# define INVALID_CHARS_IN_MAP			"Map contains invalid characters!"
# define INVALID_WALLS_IN_MAP			"Map contains invalid walls scheme!"
# define INVALID_PATH_IN_MAP			"Map does not contain a valid path!"
# define DUPLICATE_UNIT                 "Not allowed duplicated unit!"

/* ARGUMENT PASSING ERRORS */

# define INVALID_NUMBER_OF_ARGUMENTS	"Invalid number of arguments!"

/* MEMORY USING ERRORS */

# define MEMORY_ALLOCATION_FAILURE		"Memory allocation error!"

/* RENDERING ERRORS */

# define FAILED_TO_RENDER				"Failed to render the game!"
# define FAILED_TO_CREATE_WINDOW		"Failed to create new window!"
# define EXIT_IMAGE_FAILED				"Failed to load exit image!"
# define WALL_IMAGE_FAILED				"Failed to load wall image!"
# define GROUND_IMAGE_FAILED			"Failed to load ground image!"
# define PLAYER_IMAGE_FAILED			"Failed to load player image!"
# define COLLECT_IMAGE_FAILED			"Failed to load collectible image!"

/* IMAGES PATHS */

# define EXIT_IMAGE						"../Images/Exit/Exit.xpm"
# define WALL_IMAGE						"../Images/Blocks/Wall.xpm"
# define GROUND_IMAGE					"../Images/Blocks/Ground.xpm"
# define PLAYER_IMAGE					"../Images/Player/Player.xpm"
# define COLLECT_IMAGE					"../Images/Collectibles/Collectible.xpm"

/* MATRIX POSITION STRUCTURE */

typedef struct s_vector2D
{
	int		x_position;
	int		y_position;
}	t_vector2D;

/* WINDOW STRUCTURE */

typedef struct s_window
{
	int		width;
	int		height;
	void	*window;
}	t_window;

/* GAME CHARACTERS STRUCTURE */

typedef struct s_characters
{
	int			*img;
	int			total_count;
	t_vector2D	*position;
}	t_characters;


/* GENERAL GAME STRUCTURE */

typedef struct s_game
{
	t_characters	*player;
	t_characters	*collectibles;
	t_characters	*exit;
	t_characters	*wall;
	t_characters	*ground;
	t_window		*window;
	void			*mlx;
	char			**map;
	char			**aux_map;
}	t_game;

/* MAP_UTILS */

char**const		read_map(char *map);
unsigned char	check_map_extension(char *map);
unsigned char	check_map_validity(char *map, t_game *game);

/* UTILS */

void			handle_error(char *error);
void			end_and_free_game(t_game *game);

/* MAP_PARSING */

unsigned char	check_map_content(t_game *game);

/* FLOOD_FILL */

unsigned char	check_valid_path(t_game *game);

/* RENDER */

void			setting_window_size(t_game *game);
unsigned char	render_game(t_game *game);

#endif