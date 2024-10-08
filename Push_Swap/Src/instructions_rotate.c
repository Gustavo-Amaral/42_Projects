/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:11:34 by gamaral           #+#    #+#             */
/*   Updated: 2023/11/26 19:07:42 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Push_Swap.h"

static void	rotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	if (!stack || ft_lstsize(*stack) < 2)
		return ;
	head = *stack;
	tail = ft_lstlast(*stack);
	*stack = (*stack)->next;
	head->next = NULL;
	tail->next = head;
}

void	ra(t_list **stack_a, unsigned int print)
{
	rotate(stack_a);
	if (print)
		ft_putendl_fd("ra", 1);
}

void	rb(t_list **stack_b, unsigned int print)
{
	rotate(stack_b);
	if (print)
		ft_putendl_fd("rb", 1);
}

void	rr(t_list **stack_a, t_list **stack_b, unsigned int print)
{
	if (!stack_a || ft_lstsize(*stack_a) < 2 || 
		!stack_b || ft_lstsize(*stack_b) < 2)
		return ;
	rotate(stack_a);
	rotate(stack_b);
	if (print)
		ft_putendl_fd("rr", 1);
}
