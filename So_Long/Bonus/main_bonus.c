/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:35:37 by gamaral           #+#    #+#             */
/*   Updated: 2023/10/08 21:51:34 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
	{
		handle_error(INVALID_NUMBER_OF_ARGUMENTS, NULL);
		return (1);
	}
	if (!check_map_extension(argv[1]))
		return (1);
	game = game_struct_init(game);
	if (!check_map_validity(argv[1], game))
		return (1);
	if (!render_enemies(game))
		return (1);
	if (!render_game(game))
		return (1);
	return (0);
}
