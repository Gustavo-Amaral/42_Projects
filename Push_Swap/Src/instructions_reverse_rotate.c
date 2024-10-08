/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_reverse_rotate.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:13:34 by gamaral           #+#    #+#             */
/*   Updated: 2023/11/26 19:07:32 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Push_Swap.h"

static void	reverse_rotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	if (!stack || ft_lstsize(*stack) < 2)
		return ;
	head = *stack;
	tail = ft_lstlast(*stack);
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	tail->next = *stack;
	*stack = tail;
}

void	rra(t_list **stack_a, unsigned int print)
{
	reverse_rotate(stack_a);
	if (print)
		ft_putendl_fd("rra", 1);
}

void	rrb(t_list **stack_b, unsigned int print)
{
	reverse_rotate(stack_b);
	if (print)
		ft_putendl_fd("rrb", 1);
}

void	rrr(t_list **stack_a, t_list **stack_b, unsigned int print)
{
	if (!stack_a || ft_lstsize(*stack_a) < 2 || 
		!stack_b || ft_lstsize(*stack_b) < 2)
		return ;
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	if (print)
		ft_putendl_fd("rrr", 1);
}
