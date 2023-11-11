/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:44:52 by gamaral           #+#    #+#             */
/*   Updated: 2023/11/11 19:51:13 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Push_Swap.h"

int	find_index(t_list **stack, int value)
{
	int		i;
	t_list	*aux;

	i = 0;
	aux = *stack;
	while (*(int *)aux->content != value)
	{
		aux = aux->next;
		i++;
	}
	
	return (i);
}