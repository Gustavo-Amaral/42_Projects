/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavo <gustavo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:05:22 by gamaral           #+#    #+#             */
/*   Updated: 2024/08/17 00:56:28 by gustavo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/Pipex_bonus.h"
#include "Includes/Pipex.h"

void	here_doc(char *limiter)
{
	int		p_fd[2];
	pid_t	pid;
	char*	line;

	if (pipe(p_fd) == -1)
		handle_errors(PIPE_ERROR);
	pid = fork();
	if (pid == -1)
		handle_errors(FORK_ERROR);
	if (pid == 0)
	{
		close(p_fd[0]);
		while (get_next_line_bonus(&line))
		{
			if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
				exit(EXIT_SUCCESS);
			write(p_fd[1], line, ft_strlen(line));
		}
	}
	else
	{
		close(p_fd[1]);
		dup2(p_fd[0], STDIN_FILENO);
		wait(NULL);
	}
}

void	children_execution(char *argv, char **envp)
{
	pid_t	pid;
	int		file_descriptor[2];

	if (pipe(file_descriptor) == -1)
		handle_errors(PIPE_ERROR);
	pid = fork();
	if (pid == -1)
		handle_errors(FORK_ERROR);
	if (pid == 0)
	{
		close(file_descriptor[0]);
		dup2(file_descriptor[1], STDOUT_FILENO);
		execute_commands(argv, envp);
	}
	else
	{
		close(file_descriptor[1]);
		dup2(file_descriptor[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		i;
	int		fd_out;
	int		fd_in;

	if (argc >= 5)
	{
		if (ft_strcmp(argv[1], HERE_DOC) == 0)
		{
			i = 3;
			fd_out = open_file(argv[argc - 1], 2);
			here_doc(argv[2]);
		}
		else
		{
			i = 2;
			fd_out = open_file(argv[argc - 1], 1);
			fd_in = open_file(argv[1], 2);
			dup2(fd_in, STDIN_FILENO);
		}
		while (i < argc - 2)
			children_execution(argv[i++], envp);
		dup2(fd_out, STDOUT_FILENO);
		execute_commands(argv[argc - 2], envp);
	}
	handle_errors(INCORRECT_ARGUMENTS);
}
