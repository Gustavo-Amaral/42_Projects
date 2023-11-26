/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:03:58 by gamaral           #+#    #+#             */
/*   Updated: 2023/11/26 21:08:17 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Push_Swap.h"

void	handle_error_checker(t_list **stack_a, t_list **stack_b, char *error)
{
	if (stack_a)
		lst_free(stack_a);
	if (stack_b)
		lst_free(stack_b);
	ft_putendl_fd(error, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	compare_input_operation(t_list **stack_a, t_list **stack_b, char *operation)
{
	if (ft_strcmp(operation, "pa\n") == 0)
		pa(stack_a, stack_b, FALSE);
	else if (ft_strcmp(operation, "pb\n") == 0)
		pb(stack_b, stack_a, FALSE);
	else if (ft_strcmp(operation, "sa\n") == 0)
		sa(stack_a, FALSE);
	else if (ft_strcmp(operation, "sb\n") == 0)
		sb(stack_b, FALSE);
	else if (ft_strcmp(operation, "ss\n") == 0)
		ss(stack_a, stack_b, FALSE);
	else if (ft_strcmp(operation, "ra\n") == 0)
		ra(stack_a, FALSE);
	else if (ft_strcmp(operation, "rb\n") == 0)
		rb(stack_b, FALSE);
	else if (ft_strcmp(operation, "rr\n") == 0)
		rr(stack_a, stack_b, FALSE);
	else if (ft_strcmp(operation, "rra\n") == 0)
		rra(stack_a, FALSE);
	else if (ft_strcmp(operation, "rrb\n") == 0)
		rrb(stack_b, FALSE);
	else if (ft_strcmp(operation, "rrr\n") == 0)
		rrr(stack_a, stack_b, FALSE);
	else
		handle_error_checker(stack_a, stack_b, "Error");
}

void	check_operation_input(t_list **stack_a, t_list **stack_b, char *input)
{
	char	*aux;

	if (!input)
		return ;
	while (input && *input != 4)
	{
		aux = input;
		compare_input_operation(stack_a, stack_b, input);
		input = get_next_line(STDIN_FILENO);
		free(aux);
	}
	free (input);
	if (*stack_b)
		ft_printf("KO\n");
	else if (!is_sorted(stack_a))
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	lst_free(stack_a);
	lst_free(stack_b);
}

void	init_checker_stack(t_list **stack, int argc, char **argv)
{
	t_list	*new;
	char	**args;
	int		*aux;
	int		i;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		aux = malloc(sizeof(int *));
		*aux = ft_atoi(args[i]);
		new = ft_lstnew(aux, i);
		ft_lstadd_back(stack, new);
		i++;
	}
	if (argc == 2)
		array_free(args);
}
