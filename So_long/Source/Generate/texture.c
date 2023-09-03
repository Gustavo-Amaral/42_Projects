/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 21:10:59 by gamaral           #+#    #+#             */
/*   Updated: 2023/09/03 21:29:18 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

t_data	*generate_jump_2(t_vars *vars, t_data *sprites)
{
	sprites[3] = generate_image(*vars, "CAMINHO PARA A IMAGEM 3", &vars->img_lst);
	if (!sprites[4].img)
		return (NULL);
	sprites[4] = generate_image(*vars, "CAMINHO PARA A IMAGEM 4", &vars->img_lst);
	if (!sprites[4].img)
		return (NULL);
	sprites[5] = generate_image(*vars, "CAMINHO PARA A IMAGEM 5", &vars->img_lst);
	if (!sprites[5].img)
		return (NULL);
	sprites[6] = generate_image(*vars, "CAMINHO PARA A IMAGEM 6", &vars->img_lst);
	if (!sprites[6].img)
		return (NULL);
	sprites[7] = generate_image(*vars, "CAMINHO PARA A IMAGEM 7", &vars->img_lst);
	if (!sprites[7].img)
		return (NULL);
	return (sprites);
}

t_data	*generate_jump(t_vars *vars)
{
	t_data	*sprites;

	sprites = malloc(sizeof(t_data) * 8);
	if (!sprites)
		return (NULL);
	sprites[0] = generate_image(*vars, "CAMINHO PARA A IMAGEM 0", &vars->img_lst);
	if (!sprites[0].img)
		return (NULL);
	sprites[1] = generate_image(*vars, "CAMINHO PARA A IMAGEM 1", &vars->img_lst);
	if (!sprites[1].img)
		return (NULL);
	sprites[2] = generate_image(*vars, "CAMINHO PARA A IMAGEM 2", &vars->img_lst);
	if (!sprites[2].img)
		return (NULL);
	return (generate_jump_2(vars, sprites));
}
