/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 20:36:16 by gamaral           #+#    #+#             */
/*   Updated: 2023/09/02 21:16:23 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

char    *read_file(int fildes, t_alloc **alloc)
{
    int		read_val;
	char	*str;
	char	*tmp;
	char	buff[1084];

	str = NULL;
	read_val = 1;
	while (read_val)
	{
		read_val = read(fildes, buff, 1084);
		buff[read_val] = '\0';
		tmp = str;
		ft_lstadd_back(ft_lstnew(str));
		str = ft_strjoin(tmp, buff);
	}
	return (str);
}       