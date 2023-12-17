/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 21:45:44 by gamaral           #+#    #+#             */
/*   Updated: 2023/11/11 19:04:33 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*aux;

	aux = *lst;
	if (!new || !lst)
		return ;
	if (!*lst)
	{
		new->next = NULL;
		new->prev = NULL;
		*lst = new;
		return ;
	}
	aux = ft_lstlast(*lst);
	aux->next = new;
	new->next = NULL;
	new->prev = aux;
}
