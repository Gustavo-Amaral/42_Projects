/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:27:13 by gamaral           #+#    #+#             */
/*   Updated: 2023/08/13 23:13:27 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../Libft/libft.h"

# define FALSE          false
# define TRUE           true

# define MAP_NAME_CORRECT               0
# define MAP_NOT_RECTANGULAR            1
# define MAP_NOT_CLOSED                 2
# define DUPLICATE_UNIT                 3
# define MAP_NAME_INCORRECT             4
# define MAP_NAME_EXTENSION_INCORRECT   5
# define INVALID_NUMBER_OF_ARGUMENTS	6
# define MEMORY_ALLOCATION_FAILURE		7
# define MAP_IS_A_DIRECTORY				8
# define MAP_IS_TOO_BIG					9


typedef struct s_vector2D
{
	int	x;
	int y;
} t_vector2D;

typedef struct s_vars
{
    void    		*mlx;
    void    		*window;
    t_list  		*lst;
    t_list  		*img_lst;
	char			**map;
	int				total_items;
	t_vector2D		size;
} t_vars;

#endif