/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:44:52 by gamaral           #+#    #+#             */
/*   Updated: 2023/11/26 14:02:36 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Push_Swap.h"

int	ft_lst_find_index_ps(t_list *list_head, int value)
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

int	get_max_value(t_list **stack)
{
	t_list	*node;
	int		max;

	node = *stack;
	max = *(int *)node->content;
	while (node)
	{
		if (*(int *)node->content > max)
			max = *(int *)node->content;
		node = node->next;
	}
	return (max);
}

int	get_min_value(t_list **stack)
{
	t_list	*node;
	int		min;

	node = *stack;
	min = *(int *)node->content;
	while (node)
	{
		if (*(int *)node->content < min)
			min = *(int *)node->content;
		node = node->next;
	}
	return (min);
}

int	find_place_in_b(t_list *head_b, int push_value)
{
	int		index;
	t_list	*aux;

	index = 1;
	if (push_value > *(int *)head_b->content && push_value < *(int *)(ft_lstlast(head_b)->content))
		index = 0;
	else if (push_value > get_max_value(&head_b) || push_value < get_min_value(&head_b))
		index = ft_lst_find_index_ps(head_b, get_max_value(&head_b));
	else
	{
		aux = head_b->next;
		while (*(int *)head_b->content < push_value || *(int *)aux->content > push_value)
		{
			head_b = head_b->next;
			aux = head_b->next;
			index++;
		}
	}
	return (index);
}

int	find_place_in_a(t_list *head_a, int push_value)
{
	int		index;
	t_list	*aux;

	index = 1;
	if (push_value < *(int *)head_a->content && push_value > *(int *)(ft_lstlast(head_a)->content))
		index = 0;
	else if (push_value > get_max_value(&head_a) || push_value < get_min_value(&head_a))
		index = ft_lst_find_index_ps(head_a, get_min_value(&head_a));
	else
	{
		aux = head_a->next;
		while (*(int *)head_a->content > push_value || *(int *)aux->content < push_value)
		{
			head_a = head_a->next;
			aux = head_a->next;
			index++;
		}
	}
	return (index);
}
