/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprintone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 18:00:00 by gamaral           #+#    #+#             */
/*   Updated: 2023/11/19 13:56:04 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprintone(t_list *lst_elem)
{
	if (!lst_elem)
		return ;
	ft_printf("List element %d value (int): %d\n", lst_elem->index,
		*(int *)(lst_elem->content));
}
