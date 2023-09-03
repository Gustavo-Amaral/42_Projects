/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 20:57:37 by gamaral           #+#    #+#             */
/*   Updated: 2023/09/03 17:57:32 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

int	random_nb(t_vars *vars)
{
	vars->bit = ((vars->seed) ^ (vars->seed >> 2) 
			^ (vars->seed >> 3) ^ (vars->seed >> 5)) & 1;
	vars->seed = (vars->seed >> 1) | (vars->bit << 15);
	return (vars->seed);
}
