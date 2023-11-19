/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_needs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 21:31:28 by gamaral           #+#    #+#             */
/*   Updated: 2023/11/19 21:50:34 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Push_Swap.h"

int	rotate_needs_a_to_b(t_list *head_a, t_list *head_b)
{
	int 	cost;
	t_list	*aux;

	aux = head_a;
	cost = ft_case_rrarrb(head_a, head_b, *(int *)head_a->content);
	while (aux)
	{
		if (cost > ft_case_rarb(head_a, head_b, *(int *)aux->content))
			cost = ft_case_rarb(head_a, head_b, *(int *)aux->content);
		else if(cost > ft_case_rrarrb(head_a, head_b, *(int *)aux->content))
			cost = ft_case_rrarrb(head_a, head_b, *(int *)aux->content);
		else if(cost > ft_case_rarrb(head_a, head_b, *(int *)aux->content))
			cost = ft_case_rarrb(head_a, head_b, *(int *)aux->content);
		else if(cost > ft_case_rrarb(head_a, head_b, *(int *)aux->content))
			cost = ft_case_rrarb(head_a, head_b, *(int *)aux->content);
		aux = aux->next;
	}
}

int	rotate_needs_b_to_a(t_list *head_a, t_list *head_b)
{
	int 	cost;
	t_list	*aux;

	aux = head_b;
	cost = ft_case_rrarrb_a(head_a, head_b, *(int *)head_b->content);
	while (aux)
	{
		if (cost > ft_case_rarb_a(head_a, head_b, *(int *)aux->content))
			cost = ft_case_rarb_a(head_a, head_b, *(int *)aux->content);
		else if(cost > ft_case_rrarrb_a(head_a, head_b, *(int *)aux->content))
			cost = ft_case_rrarrb_a(head_a, head_b, *(int *)aux->content);
		else if(cost > ft_case_rarrb_a(head_a, head_b, *(int *)aux->content))
			cost = ft_case_rarrb_a(head_a, head_b, *(int *)aux->content);
		else if(cost > ft_case_rrarb_a(head_a, head_b, *(int *)aux->content))
			cost = ft_case_rrarb_a(head_a, head_b, *(int *)aux->content);
		aux = aux->next;
	}
}
