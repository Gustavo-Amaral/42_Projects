/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprintall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 18:48:55 by gamaral           #+#    #+#             */
/*   Updated: 2023/10/22 18:51:16 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprintall(t_list *list_head)
{
	t_list	*aux;

	if (!list_head)
		return ;
	aux = list_head;
	while (aux)
	{
		ft_lstprintone(aux);
		aux = aux->next;
	}
}
