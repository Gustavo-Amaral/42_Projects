/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 21:58:03 by gamaral           #+#    #+#             */
/*   Updated: 2023/09/03 21:09:43 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

void	init_vars(t_vars *vars)
{
	vars->mlx = NULL;
	vars->window = NULL;
	vars->lst = NULL;
	vars->img_lst = NULL;
}

static int	global_init_4(t_vars *vars)
{
	vars->items = 0;
	vars->player.direction = SOUTHEAST;
	vars->update = 0;
	vars->window = mlx_new_window(vars->mlx, (vars->size.y * 64), \
				(vars->size.x * 32) + 43, "so_long Gustavo Amaral");
	vars->jump = generate_jump(vars);
	vars->last_position = search_char(vars->map, 'P');
	vars->player.position = vars->last_position;
	vars->sprites = generate_sprites(vars);
	vars->player.sprite = generate_player(vars);
	if (!vars->jump || !vars->window || !vars->sprites || !vars->player.sprite)
		return (MEMORY_ALLOCATION_FAILURE);
	return (1);
}

static int	global_init_3(t_vars *vars)
{
	int	i;

	vars->seed = random_seed(30, vars->random);
	close(vars->random);
	i = 0;
	while (vars->map[i])
	{
		vars->save[i] = ft_strdup(vars->map[i]);
		if (!vars->save)
			return (MEMORY_ALLOCATION_FAILURE);
		i++;
	}
	vars->save[i] = NULL;
	if (vars->size.x > 40 || vars->size.y > 40)
		return (MAP_IS_TOO_BIG);
	return (global_init_4(vars));
}

static int	global_init_2(t_vars *vars, int fildes_or_error, char **argv)
{
	fildes_or_error = open(argv[1], O_RDONLY | O_NOFOLLOW | O_NOCTTY);
	vars->map = read_map(&fildes_or_error, &vars->size, 
			&vars->total_items, vars);
	close(fildes_or_error);
	if (!vars->map)
	{
		if (fildes_or_error != -1 && fildes_or_error < 0)
			return (fildes_or_error);
		else
			return (MAP_NAME_INCORRECT);
	}
	vars->map = resize_map(vars->map, &vars->size, &vars->lst);
	if (!vars->map)
	{
		end_and_free(vars);
		return (MEMORY_ALLOCATION_FAILURE);
	}
	vars->save = malloc(sizeof(char *) * (vars->size.y + 1));
	// ft_lstadd_back(ft_lstnew(vars->save));
	if (!vars->save)
		return (MEMORY_ALLOCATION_FAILURE);
	return (global_init_3(vars));
}

int	global_init(t_vars *vars, char **argv)
{
	int	fildes_or_error;

	init_vars(vars);
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return (-1);
	vars->random = open("/dev/urandom", O_RDONLY);
	if (vars->random == -1)
		return (MEMORY_ALLOCATION_FAILURE);
	fildes_or_error = open(argv[1], O_DIRECTORY);
	if (fildes_or_error >= 0)
	{
		close(fildes_or_error);
		return (MAP_IS_A_DIRECTORY);
	}
	return (global_init_2(vars, fildes_or_error, argv));
}
