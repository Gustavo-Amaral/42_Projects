/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavo <gustavo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:05:43 by gamaral           #+#    #+#             */
/*   Updated: 2024/08/17 01:00:45 by gustavo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

/* HERE DOC STRING */

# define	HERE_DOC	"here_doc"

/* UTILS_BONUS.C */

int	open_file(char *file, int in_or_out);
int	get_next_line_bonus(char **line);

#endif
