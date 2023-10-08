/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:18:45 by gamaral           #+#    #+#             */
/*   Updated: 2023/10/08 16:30:48 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Includes/So_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
	{
		handle_error(INVALID_NUMBER_OF_ARGUMENTS, NULL);
		return (0);
	}
	if (!check_map_extension(argv[1]))
		return (0);
	game = game_struct_init(game);
	if (!check_map_validity(argv[1], game))
		return (0);
	if (!render_game(game))
		return (0);
	return (0);
}
