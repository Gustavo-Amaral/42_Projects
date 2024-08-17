/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavo <gustavo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:05:43 by gamaral           #+#    #+#             */
/*   Updated: 2024/08/16 23:26:17 by gustavo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
//# include <process.h>
//# include <stdlib.h>
//# include <sys/types.h>
# include <sys/wait.h>
# include "../Libft/libft.h"

/* BOOLEAN DEFINITIONS */

# define FALSE          0
# define TRUE           1

/* STD DEFINITIONS */

# define STDIN_FILENO	0
# define STDOUT_FILENO	1
# define STDERR_FILENO	2

/* USEFUL STRINGS FOR GENERAL USE */

# define	ARGUMENT_STRUCTURE		"Incorrect arguments structure\n"
# define	COMMAND_NOT_FOUND		"Pipex: command not found: "

/* ERROR STRINGS DEFINITIONS */

# define	INCORRECT_ARGUMENTS		"Args: ./pipex <file1> <cmd1> <cmd2> <file2>\n"
# define	PIPE_ERROR 				"There was a pipe function error\n"
# define	FORK_ERROR				"There was a fork process error\n"
# define	CLD_OPEN_FILE_ERROR		"Failed to open file in child process\n"
# define	PRNT_OPEN_FILE_ERROR	"Failed to open file in parent process\n"

// typedef struct s_cmds
// {
// 	char *file1;
// 	char *file2;
// 	char *cmd1;
// 	char *cmd2;
// } t_cmds;

/* ERROR.C */

/**
 * @brief This function handle errors in case they happen and exit the program.
 * @param string: String to be printed as an error message.
 * @retval None.
*/
void	handle_errors(char *string);

/* FREEING.C */

/**
 * @brief This function frees the memory allocated for command structure and
 * its members.
 * @param commands: Command structure to be freed.
 * @retval None.
*/
//void	free_cmd_struct(t_cmds *commands);

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
//void proccess_args(int argc, char **argv, t_cmds *commands);

/* UTILS.C */

void	execute_commands(char *cmd, char **env);

#endif
