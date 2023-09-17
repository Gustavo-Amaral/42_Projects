/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 21:33:22 by gamaral           #+#    #+#             */
/*   Updated: 2023/05/07 21:40:25 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*aux;
	size_t	count;

	if (!lst)
		return (0);
	aux = lst;
	count = 1;
	while (aux->next != NULL)
	{
		aux = aux->next;
		count++;
	}
	return (count);
}
