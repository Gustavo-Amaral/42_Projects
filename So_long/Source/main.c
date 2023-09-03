/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:21:34 by gamaral           #+#    #+#             */
/*   Updated: 2023/09/03 17:55:29 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "Includes/so_long.h"
#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"

void	print_error(int error)
{
	if (error == MAP_NOT_RECTANGULAR)
		ft_putstr_fd("Error\nMap is not rectangular!\n");
	if (error == MAP_NOT_CLOSED)
		ft_putstr_fd("Error\nMap is not rectangular!\n");
	if (error == DUPLICATE_UNIT)
		ft_putstr_fd("Error\nThere is a not allowed duplicated unit!\n");
	if (error == MAP_NAME_INCORRECT)
		ft_putstr_fd("Error\nMap's name is incorrect!\n");
	if (error == MAP_NAME_EXTENSION_INCORRECT)
		ft_putstr_fd("Error\nMap's name extension is incorrect!\n");
	if (error == MEMORY_ALLOCATION_FAILURE)
		ft_putstr_fd("Error\nMemory allocation error!\n");
	if (error == MAP_IS_A_DIRECTORY)
		ft_putstr_fd("Error\nMap's name is a directory!\n");
	if (error == MAP_IS_TOO_BIG)
		ft_putstr_fd("Error\nMap is WAYYYY TOOOOO BIIIIIIG!\n");
	if (error == INVALID_CHARS_IN_MAP)
		ft_putstr_fd("Error\nMap contains invalid characters!\n");
	if (error == INVALID_WALLS_IN_MAP)
		ft_putstr_fd("Error\nMap contains invalid wall scheme!\n");
}

int	is_map_name_correct(char *name, t_list **lst, int *error)
{
	char	**result;
	int		i;

	result = ft_split(name, '.');
	i = 0;
	while (result[i])
		i++;
	if (i != 2)
	{
		*error = MAP_NAME_INCORRECT;
		return (FALSE);
	}
	if (!(ft_strncmp(result[i - 1], "ber", ft_strlen(result[i - 1])) == 0))
	{
		*error = MAP_NAME_EXTENSION_INCORRECT;
		return (FALSE);
	}
	return (TRUE);
}

Bool	check_initialization_error(int argc, char**argv, t_vars *var)
{
	int	error;

	error = 0;
	if (argc != 2)
	{
		error = INVALID_NUMBER_OF_ARGUMENTS; 
		print_error(error);
		return (FALSE);
	}
	if (argc == 2 && !(is_map_name_correct(argv[1], &var->lst, &error)))
	{
		print_error(error);
		end_and_free(var); // funcao ainda nao feita
		return (FALSE);
	}
	error = global_init(vars, argv);
	if (error)
	{
		end_and_free(vars); // funcao ainda nao feita
		print_error(error);
		return (FALSE);
	}
	return (TRUE);
}

int	main(int argc, char **argv)
{
	t_vars	var;

	var.lst = NULL;
	var.img_lst = NULL;
	if (!check_initialization_error(argc, argv, &var))
	{
		return ();
	}
	var.mlx = mlx_init();
	var.window = mlx_new_window(var.mlx, 500, 500, "So_long - Gustavo Amaral");
	mlx_loop(var.mlx);
	return (0);
}
