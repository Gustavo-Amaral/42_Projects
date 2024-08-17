/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavo <gustavo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:51:43 by gamaral           #+#    #+#             */
/*   Updated: 2024/08/16 23:26:34 by gustavo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Pipex.h"

// void	free_cmd_struct(t_cmds *commands)
// {
//     free(commands->cmd1);
//     free(commands->cmd2);
//     free(commands);
// }

void	free_array(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
}