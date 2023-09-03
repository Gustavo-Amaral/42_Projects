/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 21:18:59 by gamaral           #+#    #+#             */
/*   Updated: 2023/09/03 21:23:03 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

t_data	generate_image(t_vars vars, char *img_path, t_list **lst)
{
	t_data	sprite;

	sprite.img = mlx_xpm_file_to_image(vars.mlx, img_path, 
			&sprite.width, &sprite.height);
	if (!sprite.img)
		return (sprite);
	sprite.addr = mlx_get_data_addr(sprite.img, &sprite.bits_per_pixel,
			&sprite.line_length, &sprite.endian);
	ft_lstadd_back(lst, ft_lstnew(sprite.img));
}
