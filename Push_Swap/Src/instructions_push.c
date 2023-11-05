/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:10:51 by gamaral           #+#    #+#             */
/*   Updated: 2023/11/05 20:07:12 by gamaral          ###   ########.fr       */
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
	ft_printf("adding %d to stack a\n", *(int *)aux->content);
	ft_lstadd_front(stack_to, aux);
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	ft_putendl_fd("pa", 1);
}

void	pb(t_list **stack_b, t_list **stack_a)
{
	push(stack_b, stack_a);
	ft_putendl_fd("pb", 1);
}
