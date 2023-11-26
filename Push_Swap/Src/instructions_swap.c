/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:10:26 by gamaral           #+#    #+#             */
/*   Updated: 2023/11/26 19:07:50 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Push_Swap.h"

static void	swap(t_list **stack)
{
	t_list	*aux;

	if (!stack || !(*stack)->next)
		return ;
	aux = *stack;
	*stack = (*stack)->next;
	aux->next = (*stack)->next;
	(*stack)->next = aux;
}

void	sa(t_list **stack_a, unsigned int print)
{
	swap(stack_a);
	if (print)
		ft_putendl_fd("sa", 1);
}

void	sb(t_list **stack_b, unsigned int print)
{
	swap(stack_b);
	if (print)
		ft_putendl_fd("sb", 1);
}

void	ss(t_list **stack_a, t_list **stack_b, unsigned int print)
{
	if (!stack_b || !(*stack_b)->next)
		return ;
	swap(stack_a);
	swap(stack_b);
	if (print)
		ft_putendl_fd("ss", 1);
}
