/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprintone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 18:00:00 by gamaral           #+#    #+#             */
/*   Updated: 2023/10/22 18:50:27 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprintone(t_list *lst_elem)
{
	if (!lst_elem)
		return ;
	ft_printf("List element value (int): %d", *(int *)lst_elem->content);
}
