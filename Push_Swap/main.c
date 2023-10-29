/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:02:34 by gamaral           #+#    #+#             */
/*   Updated: 2023/10/29 17:42:51 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Includes/Push_Swap.h"

static void	init_stack(t_list **stack, int argc, char **argv)
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
		new = ft_lstnew(aux);
		ft_lstadd_back(stack, new);
		i++;
	}
	if (argc == 2)
		array_free(args);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (argc < 2)
		return (-1);
	check_args(argc, argv);
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	*stack_a = NULL;
	*stack_b = NULL;
	init_stack(stack_a, argc, argv);
	ft_lstprintall(*stack_a);
	if (is_sorted(stack_a))
	{
		lst_free(stack_a);
		lst_free(stack_b);
		return (0);
	}
	//sort_stack(stack_a, stack_b);
	lst_free(stack_a);
	lst_free(stack_b);
	return (0);
}
