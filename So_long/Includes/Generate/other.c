/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 21:58:03 by gamaral           #+#    #+#             */
/*   Updated: 2023/08/13 23:21:40 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

void	init_vars(t_vars *vars)
{
	vars->mlx = NULL;
	vars->window = NULL;
	vars->lst = NULL;
	vars->img_lst = NULL;
}
static int	global_init_4(t_vars *vars)
{
	vars->items = 0
	vars->player.direction = SOUTHEAST;
	vars->update = 0;
	vars->window = mlx_new_window(vars->mlx, (vars->size.y * 64), \
				(vars->size.x * 32) + 43, "so_long Gustavo Amaral");
	vars->jump = generate_jump(vars);   // funcao ainda nao feita
	vars->last_pos = search_char(vars->map, 'P');   // funcao ainda nao feita
	vars->player.pos = vars->last_pos;
	vars->sprites = generate_sprites(vars);   // funcao ainda nao feita
	vars->player.sprite = generate_player(vars);   // funcao ainda nao feita
	if (!vars->jump || !vars->window || !vars->sprites || !vars->player.sprite)
		return (MEMORY_ALLOCATION_FAILURE);
	return (1);
}

static int	global_init_3(t_vars *vars)
{
	int	i;

	vars->seed = random_seed(30, vars->random);  // funcao ainda nao feita
	close(vars->random);
	i = 0;
	while (vars->map[i])
	{
		vars->save[i] = ft_strdup(vars->map[i], vars->alloc);
		if(!vars->save)
			return(MEMORY_ALLOCATION_FAILURE);
		i++;
	}
	vars->save[i] = NULL;
	if (vars->size.x > 40 || vars->size.y > 40)
		return ();
	return (global_init_4(vars));
}

static int	global_init_2(t_vars *vars, int fildes, char **argv)
{
	fildes = open(argv[1], O_RDONLY | O_NOFOLLOW | O_NOCTTY);
	vars->map = read_map(&fildes, &vars->size, &vars->total_items, vars); // funcao ainda nao feita
	if (!vars->map)
	{
		if (fildes != -1 && fildes < 0)
			return (MEMORY_ALLOCATION_FAILURE);
		else
			return (MAP_NAME_INCORRECT);
	}
	vars->map = resize_map(vars->map, &vars->size, &vars->alloc); // funcao ainda nao feita
	if (!vars->map)
	{
		end_and_free(vars); // funcao ainda nao feita
		return (MEMORY_ALLOCATION_FAILURE);
	}
	vars->save = ft_malloc(sizeof(char *) * (vars->size.y + 1), &vars->alloc); // funcao ainda nao feita
	if(!vars->save)
		return (MEMORY_ALLOCATION_FAILURE);
	return (global_init_3(vars));
}

int	global_init(t_vars *vars, char **argv)
{
	int	fildes;

	init_vars(vars);
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return (-1);
	vars->random = open("/dev/urandom", O_RDONLY);
		if (vars->random == -1)
			return (MEMORY_ALLOCATION_FAILURE);
	fildes = open(argv[1], O_DIRECTORY);
	if (fildes >= 0)
	{
		close(fd);
		return (MAP_IS_A_DIRECTORY);
	}
	return(global_init_2(vars, fildes, argv));
}