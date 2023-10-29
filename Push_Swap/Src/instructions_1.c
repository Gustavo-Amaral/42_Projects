/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 19:53:12 by gamaral           #+#    #+#             */
/*   Updated: 2023/10/29 21:18:38 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Push_Swap.h"

void	instruction_sa(t_list **stack_a)
{
	void	*aux;

	if (!stack_a || !(*stack_a)->next)
		return ;
	aux = (*stack_a)->content;
	(*stack_a)->content = (*stack_a)->next->content;
	(*stack_a)->next->content = aux;
}

void	instruction_sb(t_list **stack_b)
{
	void	*aux;

	if (!stack_b || !(*stack_b)->next)
		return ;
	aux = (*stack_b)->content;
	(*stack_b)->content = (*stack_b)->next->content;
	(*stack_b)->next->content = aux;
}

void	instruction_ss(t_list **stack_a, t_list **stack_b)
{
	instruction_sa(stack_a);
	instruction_sb(stack_b);
}

void	instruction_pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*aux;

	if (!*stack_b)
		return ;
	aux = *stack_b;
	ft_lstadd_front(stack_a, *stack_b);
	*stack_b = (*stack_b)->next;
	ft_lstdelone(aux, nulling_elements);
}

void	instruction_pb(t_list **stack_b, t_list **stack_a)
{
	t_list	*aux;

	if (!*stack_a)
		return ;
	aux = *stack_a;
	ft_lstadd_front(stack_b, *stack_a);
	*stack_a = (*stack_a)->next;
	ft_lstdelone(aux, nulling_elements);
}
