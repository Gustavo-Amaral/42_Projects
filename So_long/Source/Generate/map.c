/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 15:22:05 by gamaral           #+#    #+#             */
/*   Updated: 2023/09/03 20:18:27 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

static char	**resize_y_body(t_vector2D *size, char **new,
		char **map, t_list **lst)
{
	int	i;

	i = 0;
	while (i < size->y)
	{
		new[i] = ft_strdup(map[i]);
		if (!new[i])
			return (NULL);
		i++;
	}
	while (i < size->x)
	{
		new[i] = ft_str_add("\0", size->x, '1', lst);
		if (!new[i])
			return (NULL);
		i++;
	}
	new[i] = '\0';
	return (new);
}

static char	**resize_y(t_vector2D *size, char **map, t_list **lst)
{
	char	**new;
	int		i;

	i = 0;
	new = malloc(sizeof(char *) * (size->x + 1));
	if (!new)
		return (NULL);
	resize_y_body(size, new, map, lst);
	new[i] = '\0';
	size->y = size->x;
	return (new);
}

static char	**resize_x(t_vector2D *size, char **map, t_list **lst)
{
	char	**new;
	int		i;

	i = 0;
	new = malloc(sizeof(char *) * (size->y + 1));
	if (!new)
		return (NULL);
	while (map[i])
	{
		new[i] = ft_str_add(map[i], size->y - size->x, '1', lst);
		if (!new)
			return (NULL);
		i++;
	}
	new[i] = '\0';
	size->x = size->y;
	return (new);
}

char	**resize_map(char **map, t_vector2D *size, t_list **lst)
{
	if (size->x == size->y)
		return (map);
	else if (size->x < size->y)
		return (resize_x(size, map, lst));
	else
		return (resize_y(size, map, lst));
}
