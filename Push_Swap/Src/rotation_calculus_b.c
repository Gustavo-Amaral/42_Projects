/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_calculus_b.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 19:50:24 by gamaral           #+#    #+#             */
/*   Updated: 2023/11/19 21:51:13 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Push_Swap.h"

int	ft_case_rarb(t_list *head_a, t_list *head_b, int value)
{
	int	i;

	i = ft_find_place_b(head_b, value);
	if (i < ft_find_index(head_a, value))
		i = ft_find_index(head_a, value);
	return (i);
}

int	ft_case_rrarrb(t_list *head_a, t_list *head_b, int value)
{
	int	i;

	i = 0;
	if (ft_find_place_b(head_b, value))
		i = ft_lstsize(head_b) - ft_find_place_b(head_b, value);
	if ((i < (ft_lstsize(head_a) - ft_find_index(head_a, value))) && ft_find_index(head_a, value))
		i = ft_lstsize(head_a) - ft_find_index(head_a, value);
	return (i);
}

int	ft_case_rrarb(t_list *head_a, t_list *head_b, int value)
{
	int	i;

	i = 0;
	if (ft_find_index(head_a, value))
		i = ft_lstsize(head_a) - ft_find_index(head_a, value);
	i = ft_find_place_b(head_b, value) + i;
	return (i);
}

int	ft_case_rarrb(t_list *head_a, t_list *head_b, int value)
{
	int	i;

	i = 0;
	if (ft_find_place_b(head_b, value))
		i = ft_lstsize(head_b) - ft_find_place_b(head_b, value);
	i = ft_find_index(head_a, value) + i;
	return (i);
}
