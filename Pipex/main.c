/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavo <gustavo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:05:22 by gamaral           #+#    #+#             */
/*   Updated: 2024/08/16 23:25:35 by gustavo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/Pipex.h"

// static void initialize_cmds(t_cmds *commands)
// {
//     commands->cmd1 = NULL;
//     commands->cmd2 = NULL;
//     commands->file1 = NULL;
//     commands->file2 = NULL;
// }

// int	main(int argc, char **argv)
// {
//     t_cmds  *commands;

//     commands = (t_cmds *)malloc(sizeof(t_cmds));
// 	if (argc <= 1)
//         return (0);
//     initialize_cmds(commands);
//     proccess_args(argc, argv, commands);
//     ft_printf("Command 1: %s\nCommand 2: %s\n", commands->cmd1, commands->cmd2);
//     free_cmd_struct(commands);
// 	return (0);
// }

void	children_execution(char **argv, char **envp, int *file_descriptor)
{
	int	desc_infile;

	desc_infile = open(argv[1], O_RDONLY, 0777);
	if (desc_infile == -1)
		handle_errors(CLD_OPEN_FILE_ERROR);
	dup2(desc_infile, STDIN_FILENO);
	dup2(file_descriptor[1], STDOUT_FILENO);
	close(file_descriptor[0]);
	execute_commands(argv[2], envp);
}

void	parent_execution(char **argv, char **envp, int *file_descriptor)
{
	int	desc_outfile;

	desc_outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (desc_outfile == -1)
		handle_errors(PRNT_OPEN_FILE_ERROR);
	dup2(desc_outfile, STDOUT_FILENO);
	dup2(file_descriptor[0], STDIN_FILENO);
	close(file_descriptor[1]);
	execute_commands(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		file_descriptor[2];
	pid_t	process_id;

	if (argc == 5)
	{
		if (pipe(file_descriptor) == -1)
			handle_errors(PIPE_ERROR);
		process_id = fork();
		if (process_id == -1)
			handle_errors(FORK_ERROR);
		if (process_id == 0)
			children_execution(argv, envp, file_descriptor);
		waitpid(process_id, NULL, 0);
		parent_execution(argv, envp, file_descriptor);
	}
	else
	{
		ft_putstr_fd(ARGUMENT_STRUCTURE, STDOUT_FILENO);
		handle_errors(INCORRECT_ARGUMENTS);
	}
	return (0);
}
