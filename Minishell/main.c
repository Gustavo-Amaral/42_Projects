/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:05:22 by gamaral           #+#    #+#             */
/*   Updated: 2023/12/17 19:28:15 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/Minishell.h"

static void initialize_cmds(t_cmds *commands)
{
    commands->cmd1 = NULL;
    commands->cmd2 = NULL;
}

int	main(int argc, char **argv)
{
    t_cmds  *commands;

    commands = (t_cmds *)malloc(sizeof(t_cmds));
	if (argc <= 1)
        return (0);
    initialize_cmds(commands);
    proccess_args(argc, argv, commands);
    ft_printf("Command 1: %s\nCommand 2: %s\n", commands->cmd1, commands->cmd2);
    free_cmd_struct(commands);
	return (0);
}
