/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:44:48 by gamaral           #+#    #+#             */
/*   Updated: 2023/11/05 20:43:45 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Push_Swap.h"

static int	get_max_value(t_list **stack)
{
	t_list	*head;
	int		max;

	head = *stack;
	max = *(int *)head->content;
	while (head)
	{
		if (*(int *)head->content > max)
			max = *(int *)head->content;
		head = head->next;
	}
	return (max);
}

static int	get_min_value(t_list **stack)
{
	t_list	*head;
	int		min;

	head = *stack;
	min = *(int *)head->content;
	while (head)
	{
		if (*(int *)head->content < min)
			min = *(int *)head->content;
		head = head->next;
	}
	return (min);
}

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	t_list	*head_a;
	int		i;
	int		j;
	int		size;

	i = 0;
	head_a = *stack_a;
	size = ft_lstsize(head_a);
	while ()
	{
		
	}
}
