/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:18:45 by gamaral           #+#    #+#             */
/*   Updated: 2023/09/17 19:09:34 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Includes/So_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
	{
		handle_error(INVALID_NUMBER_OF_ARGUMENTS);
		return (0);
	}
	if (!check_map_extension(argv[1]))
		return (0);
	if (!check_map_validity(argv[1], game))
		return (0);
	if (!render_game(game))
		return (0);
	return (0);
}
