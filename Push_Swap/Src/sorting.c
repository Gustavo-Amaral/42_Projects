/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:44:48 by gamaral           #+#    #+#             */
/*   Updated: 2023/11/05 21:10:11 by gamaral          ###   ########.fr       */
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
	int		max;
	int		min;
	int		size;

	head_a = *stack_a;
	size = ft_lstsize(head_a);
	max = get_max_value(stack_a);
	min = get_min_value(stack_a);
	while (ft_lstsize(*stack_a) < size && !is_sorted(stack_a))
	{
		if (ft_lstsize(*stack_a) > 3)
		{
			pb(stack_b, stack_a);
			if (!is_sorted(stack_b))
			{
				if (ft_lstsize(*stack_b) == 2)
					sb(stack_b);
				else
				{
					
				}
			}
		}
	}
}
