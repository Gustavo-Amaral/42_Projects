/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavo <gustavo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:07:57 by gustavo           #+#    #+#             */
/*   Updated: 2024/08/16 23:39:38 by gustavo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Pipex.h"

char*	ft_get_env_var(char* name, char** env)
{
	int		i;
	int		j;
	char*	env_var_name;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		env_var_name = ft_substr(env[i], 0, j);
		if (ft_strcmp(env_var_name, name) == 0)
		{
			free(env_var_name);
			return (env[i] + j + 1);
		}
		free(env_var_name);
		i++;
	}
	return (NULL);
}

char*	get_path(char* cmd, char **env)
{
	int		i;
	char*	exec;
	char**	full_path;
	char*	part_path;
	char**	s_cmd;

	i = -1;
	full_path = ft_split(ft_get_env_var("PATH", env), ':');
	s_cmd = ft_split(cmd, ' ');
	while (full_path[++i])
	{
		part_path = ft_strjoin(full_path[i], "/");
		exec = ft_strjoin(part_path, s_cmd[0]);
		ft_printf("exec: %s\n", exec);
		free(part_path);
		if (access(exec, F_OK | X_OK) == 0)
		{
			free_array(s_cmd);
			free_array(full_path);
			return (exec);
		}
	}
	free_array(full_path);
	free_array(s_cmd);
	return (cmd);
}

void	execute_commands(char *cmd, char **env)
{
	char	**s_cmd;
	char	*path;

	s_cmd = ft_split(cmd, ' ');
	path = get_path(s_cmd[0], env);
	if (execve(path, s_cmd, env) == -1)
	{
		ft_putstr_fd(COMMAND_NOT_FOUND, STDERR_FILENO);
		ft_putendl_fd(s_cmd[0], STDERR_FILENO);
		free_array(s_cmd);
		exit(EXIT_SUCCESS);
	}
}
