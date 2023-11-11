/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprintone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 18:00:00 by gamaral           #+#    #+#             */
/*   Updated: 2023/10/29 17:12:55 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprintone(t_list *lst_elem)
{
	static int	index;

	if (!lst_elem)
		return ;
	ft_printf("List element %d value (int): %d\n", index++,
		*(int *)(lst_elem->content));
}
