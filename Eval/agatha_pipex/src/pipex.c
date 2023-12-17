/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathabarros <agathabarros@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:23:11 by agathabarro       #+#    #+#             */
/*   Updated: 2023/08/23 10:19:07 by agathabarro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/** the function check_envp() checks if the PATH 
 * variable is set in the environment
 * if not, it prints an error message and exits the program
 */
void	check_args(int argc)
{
	if (argc != 5)
	{
		ft_putstr_fd("Error: wrong number of arguments\n", 2);
		ft_putstr_fd("Usage: ./pipex infile cmd1 cmd2 outfile\n", 1);
		exit(1);
	}
}

void	check_envp(char **envp)
{
	int	i;
	int	check;

	i = -1;
	check = 0;
	while (envp[++i])
		if (ft_strnstr(envp[i], "PATH=", 5) && envp[i][6])
			check = 1;
	if (!check)
	{
		error();
		exit(1);
	}
}

/**
 * the child_process() function executes the first command
 * it takes the command and the environment as parameters
 * it opens the input file
 * it redirects the output to the pipe
 * it redirects the input to the input file
 * it closes the pipe
 * it executes the command
 * it exits the child process
 */
void	child_process(char **argv, char **envp, int *fd)
{
	int	in;

	in = open(argv[1], O_RDONLY, 0777);
	if (in == -1)
		error();
	dup2(fd[1], STDOUT_FILENO);
	dup2(in, STDIN_FILENO);
	close(fd[0]);
	execute(argv[2], envp);
}

/**
 * the function parent_process() executes the second command
 * it takes the command and the environment as parameters
 * it opens the output file
 * it redirects the input to the pipe
 * it redirects the output to the output file
 * it closes the pipe
 * 
*/
void	parent_process(char **argv, char **envp, int *fd)
{
	int	out;

	out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0755); 
	if (out == -1)
		error();
	dup2(fd[0], STDIN_FILENO);
	dup2(out, STDOUT_FILENO);
	close(fd[1]);
	execute(argv[3], envp);
}

/**
 * the function main() checks if the number of arguments is correct
 * if the arguments are correct, it creates a pipe
 * and forks the process into a child and a parent process
 * the child process executes the first command
 * the parent process executes the second command
 * the parent process waits for the child process to finish
 * the parent process closes the pipe
 * the parent process executes the second command
 * if the arguments are not correct, it prints an error message
 * and exits the program
*/
int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	check_envp(envp);
	check_args(argc);
	if (pipe(fd) == -1)
		error();
	pid = fork();
	if (pid == -1)
		error();
	if (pid == 0)
		child_process(argv, envp, fd);
	waitpid(pid, NULL, 0);
	parent_process(argv, envp, fd);
}
