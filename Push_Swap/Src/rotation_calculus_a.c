/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_calculus_a.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 19:50:26 by gamaral           #+#    #+#             */
/*   Updated: 2023/11/26 13:57:17 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Push_Swap.h"

int	ft_case_rarb_a(t_list *head_a, t_list *head_b, int value)
{
	int	i;

	i = find_place_in_a(head_a, value);
	if (i < ft_lst_find_index_ps(head_b, value))
		i = ft_lst_find_index_ps(head_b, value);
	return (i);
}

int	ft_case_rrarrb_a(t_list *head_a, t_list *head_b, int value)
{
	int	i;

	i = 0;
	if (find_place_in_a(head_a, value))
		i = ft_lstsize(head_a) - find_place_in_a(head_a, value);
	if ((i < (ft_lstsize(head_b) - ft_lst_find_index_ps(head_b, value))) && ft_lst_find_index_ps(head_b, value))
		i = ft_lstsize(head_b) - ft_lst_find_index_ps(head_b, value);
	return (i);
}

int	ft_case_rarrb_a(t_list *head_a, t_list *head_b, int value)
{
	int	i;

	i = 0;
	if (ft_lst_find_index_ps(head_b, value))
		i = ft_lstsize(head_b) - ft_lst_find_index_ps(head_b, value);
	i = find_place_in_a(head_a, value) + i;
	return (i);
}

int	ft_case_rrarb_a(t_list *head_a, t_list *head_b, int value)
{
	int	i;

	i = 0;
	if (find_place_in_a(head_a, value))
		i = ft_lstsize(head_a) - find_place_in_a(head_a, value);
	i = ft_lst_find_index_ps(head_b, value) + i;
	return (i);
}
