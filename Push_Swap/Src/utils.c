/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:52:57 by gamaral           #+#    #+#             */
/*   Updated: 2023/10/29 17:39:12 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Push_Swap.h"

void	handle_error(int argc, char **argv, char *error)
{
	if (argc == 2)
		array_free(argv);
	ft_putendl_fd(error, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

static unsigned char	is_num(char *num_str)
{
	int	i;

	i = 0;
	if (num_str[0] == '-')
		i++;
	while (num_str[i])
	{
		if (ft_isdigit(num_str[i]))
			return (TRUE);
		i++;
	}
	return (FALSE);
}

static unsigned char	is_duplicate_arg(char *arg, char **args, int index)
{
	while (args[index])
	{
		if (!ft_strcmp(arg, args[index]))
			return (TRUE);
		index++;
	}
	return (FALSE);
}

void	check_args(int argc, char **argv)
{
	char	**args;
	long	tmp;
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
		tmp = ft_atoi(args[i]);
		if (tmp < INT_MIN || tmp > INT_MAX)
			handle_error(argc, args, "Error");
		if (!is_num(args[i]))
			handle_error(argc, args, "Error");
		if (is_duplicate_arg(args[i], args, i + 1))
			handle_error(argc, args, "Error");
		i++;
	}
	if (argc == 2)
		array_free(args);
}

int	is_sorted(t_list **stack)
{
	t_list	*head;
	int		value_head;
	int		value_next;

	head = *stack;
	while(head && head->next)
	{
		value_head = *(int *)(head->content);
		value_next = *(int *)(head->next->content);
		if(value_next < value_head)
			return (FALSE);
		head = head->next;
	}
	return (TRUE);
}
