/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:10:51 by gamaral           #+#    #+#             */
/*   Updated: 2023/11/26 19:08:12 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Push_Swap.h"

static void	push(t_list **stack_to, t_list **stack_from)
{
	t_list	*aux;

	if (!*stack_from || !stack_to)
		return ;
	aux = *stack_from;
	*stack_from = (*stack_from)->next;
	aux->next = NULL;
	ft_lstadd_front(stack_to, aux);
}

void	pa(t_list **stack_a, t_list **stack_b, unsigned int print)
{
	push(stack_a, stack_b);
	if (print)
		ft_putendl_fd("pa", 1);
}

void	pb(t_list **stack_b, t_list **stack_a, unsigned int print)
{
	push(stack_b, stack_a);
	if (print)
		ft_putendl_fd("pb", 1);
}
