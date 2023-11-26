/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_operate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 22:19:27 by gamaral           #+#    #+#             */
/*   Updated: 2023/11/26 15:40:51 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Push_Swap.h"

int	apply_ra_rb(t_list **stack_a, t_list **stack_b, int value, char stack_sel)
{
	if (stack_sel == 'a' || stack_sel == 'A')
	{
		while (*(int *)(*stack_a)->content != value && find_place_in_b(*stack_b, value) > 0)
			rr(stack_a, stack_b);
		while (*(int *)(*stack_a)->content != value)
			ra(stack_a);
		while (find_place_in_b(*stack_b, value) > 0)
			rb(stack_b);
		pb(stack_b, stack_a);
	}
	else
	{
		while (*(int *)(*stack_b)->content != value && find_place_in_a(*stack_a, value) > 0)
			rr(stack_a, stack_b);
		while (*(int *)(*stack_b)->content != value)
			rb(stack_b);
		while (find_place_in_a(*stack_a, value) > 0)
			ra(stack_a);
		pa(stack_a, stack_b);
	}
	return (-1);
}

int	apply_rra_rrb(t_list **stack_a, t_list **stack_b, int value, char stack_sel)
{
	if (stack_sel == 'a' || stack_sel == 'A')
	{
		while (*(int *)(*stack_a)->content != value && find_place_in_b(*stack_b, value) > 0)
			rrr(stack_a, stack_b);
		while (*(int *)(*stack_a)->content != value)
			rra(stack_a);
		while (find_place_in_b(*stack_b, value) > 0)
			rrb(stack_b);
		pb(stack_b, stack_a);
	}
	else
	{
		while (*(int *)(*stack_b)->content != value && find_place_in_a(*stack_a, value) > 0)
			rrr(stack_a, stack_b);
		while (*(int *)(*stack_b)->content != value)
			rrb(stack_b);
		while (find_place_in_a(*stack_a, value) > 0)
			rra(stack_a);
		pa(stack_a, stack_b);
	}
	return (-1);
}

int	apply_rra_rb(t_list **stack_a, t_list **stack_b, int value, char stack_sel)
{
	if (stack_sel == 'a' || stack_sel == 'A')
	{
		while (*(int *)(*stack_a)->content != value)
			rra(stack_a);
		while (find_place_in_b(*stack_b, value) > 0)
			rb(stack_b);
		pb(stack_b, stack_a);
	}
	else
	{
		while (find_place_in_a(*stack_a, value) > 0)
			rra(stack_a);
		while (*(int *)(*stack_b)->content != value)
			rb(stack_b);
		pa(stack_a, stack_b);
	}
	return (-1);
}

int	apply_ra_rrb(t_list **stack_a, t_list **stack_b, int value, char stack_sel)
{
	if (stack_sel == 'a' || stack_sel == 'A')
	{
		while (*(int *)(*stack_a)->content != value)
			ra(stack_a);
		while (find_place_in_b(*stack_b, value) > 0)
			rrb(stack_b);
		pb(stack_b, stack_a);
	}
	else
	{
		while (find_place_in_a(*stack_a, value) > 0)
			ra(stack_a);
		while (*(int *)(*stack_b)->content != value)
			rrb(stack_b);
		pa(stack_a, stack_b);
	}
	return (-1);
}
