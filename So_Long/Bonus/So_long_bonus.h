/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   So_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:53:57 by gamaral           #+#    #+#             */
/*   Updated: 2023/10/14 20:44:36 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../Libft/libft.h"
# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"
# include <stdlib.h>

/* BOOLEAN DEFINITIONS */

# define FALSE          0
# define TRUE           1

/* STD DEFINITIONS */

# define STDIN_FILENO	0
# define STDOUT_FILENO	1
# define STDERR_FILENO	2

/* WINDOW DEFINITIONS */

# define BLK_SIZE		70

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
# define TOTAL_COLLECTIBLES_ERROR		"You get more items than available?!"

/* ARGUMENT PASSING ERRORS */

# define INVALID_NUMBER_OF_ARGUMENTS	"Invalid number of arguments!"

/* MEMORY USING ERRORS */

# define MEMORY_ALLOCATION_FAILURE		"Memory allocation error!"

/* RENDERING ERRORS */

# define FAILED_TO_RENDER				"Failed to render the game!"
# define FAILED_TO_CREATE_WINDOW		"Failed to create new window!"
# define EXIT_IMAGE_FAILED				"Failed to load exit image!"
# define WALL_IMAGE_FAILED				"Failed to load wall image!"
# define ENEMY_IMAGE_FAILED				"Failed to load enemy image!"
# define GROUND_IMAGE_FAILED			"Failed to load ground image!"
# define PLAYER_IMAGE_FAILED			"Failed to load player image!"
# define COLLECT_IMAGE_FAILED			"Failed to load collectible image!"

/* IMAGES PATHS */

# define EXIT_IMAGE						"./Images/Exit/Exit.xpm"
# define WALL_IMAGE						"./Images/Blocks/Wall.xpm"
# define ENEMY_IMAGE					"./Images/Enemies/Enemy.xpm"
# define GROUND_IMAGE					"./Images/Blocks/Ground.xpm"
# define PLAYER_IMAGE					"./Images/Player/Player.xpm"
# define COLLECT_IMAGE					"./Images/Collectibles/Collectible.xpm"

/* MOVEMENT KEYS */

# define CAP_A	0x0041
# define CAP_D	0x0044
# define CAP_S	0x0053
# define CAP_W	0x0057

# define A	0x0061
# define D	0x0064
# define S	0x0073
# define W	0x0077

# define LEFT	0xFF51
# define RIGHT	0xFF53
# define DOWN	0xFF54
# define UP		0xFF52

/* USEFUL KEYS */

# define ESC	0xFF1B

/* MOVEMENT ORIENTATION MACROS */

# define VERTICAL	"vertical"
# define HORIZONTAL	"horizontal"

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
	t_vector2D	position;
}	t_characters;

/* GENERAL GAME STRUCTURE */

typedef struct s_game
{
	t_characters	player;
	t_characters	collectibles;
	t_characters	exit;
	t_characters	wall;
	t_characters	ground;
	t_characters	enemies;
	t_list			enemy_list;
	t_window		window;
	int				items_collected;
	int				total_moves;
	void			*mlx;
	char			**map;
	char			**aux_map;
}	t_game;

/* MAP_UTILS_BONUS */

char			**read_map(char *map, t_game *game);
unsigned char	check_map_extension(char *map);
unsigned char	check_map_validity(char *map, t_game *game);
t_game			*game_struct_init(t_game *game);

/* UTILS_BONUS */

void			ft_print_movements(t_game *game);
void			handle_error(char *error, t_game *game);
int				end_and_free_game(t_game *game);

/* MAP_PARSING_BONUS */

unsigned char	check_map_content(t_game *game);

/* FLOOD_FILL_BONUS */

unsigned char	check_valid_path(t_game *game);

/* RENDER_BONUS */

void			setting_window_size(t_game *game);
unsigned char	render_game(t_game *game);

/* HOOK_FUNCS_BONUS */

int				read_keys(int keypress, t_game *game);

/* ENEMIES_BONUS */

int				place_enemies_in_map(t_game *game);
void			init_enemy_img(t_game *game, int *blk);

/* ENEMY_MOVE */

void			mirror_enemy_move_x(t_game *game, int position, 
					char *orientation);
void			mirror_enemy_move_y(t_game *game, int position, 
					char *orientation);
void			check_player_colision(t_game *game);

#endif