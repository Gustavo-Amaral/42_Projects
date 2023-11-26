/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:44:48 by gamaral           #+#    #+#             */
/*   Updated: 2023/11/26 14:14:19 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Push_Swap.h"

void	sort_three_elements(t_list **stack_a)
{
	if (get_min_value(stack_a) == *(int *)(*stack_a)->content)
	{
		rra(stack_a);
		sa(stack_a);
	}
	else if (get_max_value(stack_a) == *(int *)(*stack_a)->content)
	{
		ra(stack_a);
		if (!is_sorted(stack_a))
			sa(stack_a);
	}
	else
	{
		if (ft_lst_find_index_ps(*stack_a, get_max_value(stack_a)) == 1)
			rra(stack_a);
		else
			sa(stack_a);
	}
}

void	sort_b_to_three(t_list **stack_a, t_list **stack_b)
{
	int		i;
	t_list	*aux;

	while (ft_lstsize(*stack_a) > 3 && !is_sorted(stack_a))
	{
		aux = *stack_a;
		i = rotate_needs_a_to_b(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == ft_case_rarb(*stack_a, *stack_b, *(int *)aux->content))
				i = apply_ra_rb(stack_a, stack_b, *(int *)aux->content, 'a');
			else if (i == ft_case_rrarrb(*stack_a, *stack_b, *(int *)aux->content))
				i = apply_rra_rrb(stack_a, stack_b, *(int *)aux->content, 'a');
			else if (i == ft_case_rarrb(*stack_a, *stack_b, *(int *)aux->content))
				i = apply_ra_rrb(stack_a, stack_b, *(int *)aux->content, 'a');
			else if (i == ft_case_rrarb(*stack_a, *stack_b, *(int *)aux->content))
				i = apply_rra_rb(stack_a, stack_b, *(int *)aux->content, 'a');
			else
				aux = aux->next;
		}
	}
}

void	sort_b(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) > 3 && !is_sorted(stack_a))
		pb(stack_b, stack_a);
	if (ft_lstsize(*stack_a) > 3 && !is_sorted(stack_a))
		pb(stack_b, stack_a);
	if (ft_lstsize(*stack_a) > 3 && !is_sorted(stack_a))
		sort_b_to_three(stack_a, stack_b);
	if (!is_sorted(stack_a))
		sort_three_elements(stack_a);
}

void	sort_a(t_list **stack_a, t_list **stack_b)
{
	int		index;
	t_list	*aux;

	while (*stack_b)
	{
		aux = *stack_b;
		index = rotate_needs_b_to_a(*stack_a, *stack_b);
		while (index >= 0)
		{
			if (index == ft_case_rarb_a(*stack_a, *stack_b, *(int *)aux->content))
				index = apply_ra_rb(stack_a, stack_b, *(int *)aux->content, 'b');
			else if (index == ft_case_rarrb_a(*stack_a, *stack_b, *(int *)aux->content))
				index = apply_ra_rrb(stack_a, stack_b, *(int *)aux->content, 'b');
			else if (index == ft_case_rrarrb_a(*stack_a, *stack_b, *(int *)aux->content))
				index = apply_rra_rrb(stack_a, stack_b, *(int *)aux->content, 'b');
			else if (index == ft_case_rrarb_a(*stack_a, *stack_b, *(int *)aux->content))
				index = apply_rra_rb(stack_a, stack_b, *(int *)aux->content, 'b');
			else
				aux = aux->next;
		}
	}
}

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	int	index;

	if (ft_lstsize(*stack_a) == 2)
		sa(stack_a);
	else
	{
		sort_b(stack_a, stack_b);
		sort_a(stack_a, stack_b);
		index = ft_lst_find_index_ps(*stack_a, get_min_value(stack_a));
		if (index < ft_lstsize(*stack_a) - index)
		{
			while (*(int *)(*stack_a)->content != get_min_value(stack_a))
				ra(stack_a);
		}
		else
		{
			while (*(int *)(*stack_a)->content != get_min_value(stack_a))
				rra(stack_a);
		}
	}
}
