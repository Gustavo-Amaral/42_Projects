/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 21:10:59 by gamaral           #+#    #+#             */
/*   Updated: 2023/09/03 21:23:18 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

t_data	*generate_jump(t_vars *vars)
{
	t_data	*sprites;

	sprites = malloc(sizeof(t_data) * 8);
	if (!sprites)
		return (NULL);
	sprites[0] = generate_image(*vars, "CAMINHO PARA A IMAGEM", &vars->img_lst);
}
