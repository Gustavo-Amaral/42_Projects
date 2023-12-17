/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:05:43 by gamaral           #+#    #+#             */
/*   Updated: 2023/12/17 19:29:00 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h> 
# include <unistd.h> 
# include <fcntl.h> 
//# include <process.h>
# include "../Libft/libft.h"

typedef struct s_cmds
{
	char *cmd1;
	char *cmd2;
} t_cmds;

/* FREEING.C */

/**
 * @brief This function frees the memory allocated for command structure and 
 * its members.
 * @param commands: Command structure to be freed.
 * @retval None.
*/
void	free_cmd_struct(t_cmds *commands);

/**
 * @brief This function frees the memory allocated for commands strings array
 * and all its member strings.
 * @param array: Array to be freed.
 * @retval None.
*/
void	free_array(char **array);

/* PROCCESS_ARGS.C */

/**
 * @brief This function parses the arguments inserted in the command line
 * and separate each command properly, in order for them to be executed later
 * on.
 * @note  Both structure variables need to be freed after its use, since memory
 * is allocated for them inside the function call.
 * @param argc: Number of arguments inserted in the command line, including
 * programs's name.
 * @param argv: Arguments inserted in the command line, in string format,
 * including program's name.
 * @retval None.
*/
void proccess_args(int argc, char **argv, t_cmds *commands);

#endif
