/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathabarros <agathabarros@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:20:13 by agathabarro       #+#    #+#             */
/*   Updated: 2023/08/22 20:54:27 by agathabarro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	error(void)
{
	perror("Error\n");
	exit(EXIT_FAILURE);
}

void	if_error(char *header, char *msg)
{
	ft_putstr_fd(header, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
}

void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free (str);
}

char	*get_path(char *cmd, char **envp)
{
	int		i;
	char	**path_envp;
	char	*path_cmd;
	char	*part_path;

	i = 0;
	while (!ft_strnstr(envp[i], "PATH=", 5))
		i++;
	path_envp = ft_split(envp[i] + 5, ':');
	i = -1;
	while (path_envp[++i])
	{
		part_path = ft_strjoin(path_envp[i], "/");
		path_cmd = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path_cmd, F_OK) == 0)
		{
			free_split(path_envp);
			return (path_cmd);
		}
		free(path_cmd);
	}
	free_split(path_envp);
	if_error(cmd, "command not found");
	return (NULL);
}

void	execute(char *cmd, char **envp)
{
	char	**cmd_flags;
	char	*path;

	cmd_flags = ft_split(cmd, ' '); 
	path = get_path(cmd_flags[0], envp);
	if (!path)
	{
		free_split(cmd_flags);
		free (path);
		exit(127);
	}
	if (execve(path, cmd_flags, envp) == -1)
	{
		free_split(cmd_flags);
		free (path);
		error();
	}
}
