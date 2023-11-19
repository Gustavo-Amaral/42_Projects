/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_find_index.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 13:57:25 by gamaral           #+#    #+#             */
/*   Updated: 2023/11/19 14:26:04 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lst_find_index(t_list *list_head, int value)
{
	int		i;
	t_list	*aux;

	i = 0;
	aux = list_head;
	while (*(int *)aux->content != value)
	{
		aux = aux->next;
		i++;
	}
	aux->index = i;
	return (aux->index);
}
