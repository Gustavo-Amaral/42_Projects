/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 22:31:15 by gamaral           #+#    #+#             */
/*   Updated: 2023/11/11 19:10:44 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*aux;

	aux = malloc(sizeof(t_list));
	if (!aux)
		return (NULL);
	aux->content = content;
	aux->next = NULL;
	aux->prev = NULL;
	return (aux);
}
