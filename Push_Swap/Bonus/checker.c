/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:03:42 by gamaral           #+#    #+#             */
/*   Updated: 2023/11/26 21:03:17 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Push_Swap.h"

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;
	char	*line;

	if (argc < 2)
		return (-1);
	check_args(argc, argv);
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	*stack_a = NULL;
	*stack_b = NULL;
	init_checker_stack(stack_a, argc, argv);
	if (is_sorted(stack_a))
	{
		lst_free(stack_a);
		lst_free(stack_b);
	}
	line = get_next_line(STDIN_FILENO);
	if (!line && !is_sorted(stack_a))
		ft_printf("KO\n");
	else if (!line && is_sorted(stack_a))
		ft_printf("OK\n");
	else
		check_operation_input(stack_a, stack_b, line);
	return (0);
}
