/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 21:18:51 by gamaral           #+#    #+#             */
/*   Updated: 2023/10/29 21:58:25 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Push_Swap.h"

void	instruction_ra(t_list **stack_a)
{
	t_list	*aux;
	int		i;

	if (!stack_a)
		return ;
	aux = *stack_a;
	i = 0;
	while (stack_a[i])
	{
		stack_a[i] = stack_a[i]->next;
		i++; 
	}
	aux->next = NULL;
	stack_a[i] = aux;
}

void	instruction_rb(t_list **stack_b)
{
	t_list	*aux;
	int		i;

	if (!stack_b)
		return ;
	aux = *stack_b;
	i = 0;
	while (stack_b[i])
	{
		stack_b[i] = stack_b[i]->next;
		i++; 
	}
	aux->next = NULL;
	stack_b[i] = aux;
}

void	instruction_rr(t_list **stack_a, t_list **stack_b)
{
	instruction_ra(stack_a);
	instruction_rb(stack_b);
}


/* CONTINUAR DAQUI */
void	instruction_rra(t_list **stack_a)
{
	t_list	*aux;
	int		i;

	if (!stack_a)
		return ;
	aux = ft_lstlast(*stack_a);
	i = ft_lstsize(*stack_a);
	while (stack_a[i])
	{
		stack_a[i] = stack_a[i]->next;
		i++; 
	}
	aux->next = NULL;
	stack_a[i] = aux;
}
