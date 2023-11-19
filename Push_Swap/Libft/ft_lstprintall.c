/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprintall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 18:48:55 by gamaral           #+#    #+#             */
/*   Updated: 2023/11/19 14:27:15 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprintall(t_list *list_head)
{
	t_list	*aux;
	int		value;

	if (!list_head)
		return ;
	aux = list_head;
	while (aux)
	{
		value = *(int *)aux->content;
		ft_lst_find_index(list_head, value);
		ft_lstprintone(aux);
		aux = aux->next;
	}
}
