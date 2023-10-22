/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:52:57 by gamaral           #+#    #+#             */
/*   Updated: 2023/10/22 21:25:30 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Push_Swap.h"

static void	array_free(char **args)
{
	while (*args)
		free(*args++);
	free(args);
}

static void	handle_error(int argc, char **argv, char *error)
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
	while (num_str)
	{
		if (!ft_isdigit(num_str[i]))
			return (TRUE);
		i++;
	}
	return (FALSE);
}

static unsigned char	is_duplicate_arg(char *arg, char **args, int index)
{
	while (args)
	{
		if (!ft_strcmp(arg, args[index]))
			return (FALSE);
	}
	return (TRUE);
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
