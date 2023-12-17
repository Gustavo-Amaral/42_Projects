/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathabarros <agathabarros@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:23:16 by agathabarro       #+#    #+#             */
/*   Updated: 2023/08/22 20:43:59 by agathabarro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <signal.h>

void	check_args(int argc);
void	check_envp(char **envp);
void	parent_process(char **argv, char **envp, int *fd);
void	child_process(char **argv, char **envp, int *fd);
void	if_error(char *header, char *msg);
void	error(void);
void	execute(char *argv, char **envp);
char	*get_path(char *cmd, char **envp);
void	free_split(char **str);

#endif
