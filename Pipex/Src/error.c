/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 20:32:19 by gamaral           #+#    #+#             */
/*   Updated: 2023/12/17 20:36:24 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Pipex.h"

void	handle_errors(char *string)
{
	ft_putstr_fd(string, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
