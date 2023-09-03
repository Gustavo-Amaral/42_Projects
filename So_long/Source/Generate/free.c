/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 20:19:19 by gamaral           #+#    #+#             */
/*   Updated: 2023/09/03 20:47:23 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

void	ft_img_clear(t_list **img_lst, void *mlx_ptr)
{
	t_list	*lst_aux;

	if (*img_lst)
	{
		while ((*img_lst)->next != NULL)
		{
			lst_aux = (*img_lst)->next;
			mlx_destroy_image(mlx_ptr, (*img_lst)->content);
			free(*img_lst);
			*img_lst = lst_aux;
		}
	}
}

void	end_and_free(t_vars *vars)
{
	ft_img_clear(&vars->img_lst, vars->mlx);
	ft_lstclear(vars->lst, free);
	if (vars->window)
		mlx_destroy_window(vars->mlx, vars->window);
	if (vars->mlx)
	{
		mlx_destroy_display((*vars).mlx);
		free((*vars).mlx);
	}
}
