/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_Swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:24:53 by gamaral           #+#    #+#             */
/*   Updated: 2023/10/22 21:24:55 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/libft.h"

/* BOOLEAN DEFINITIONS */

# define FALSE          0
# define TRUE           1

/* STD DEFINITIONS */

# define STDIN_FILENO	0
# define STDOUT_FILENO	1
# define STDERR_FILENO	2

/* INTEGER DEFINITIONS */

# define INT_MIN		-2147483648
# define INT_MAX		2147483647

/* ERROR DEFINITIONS */

# define ARGUMENT_IS_NOT_A_NUMBER	"Not a numeric argument"
# define DUPLICATE_ARGUMENT			"There is a duplicate argument"
# define ARGUMENT_BEYOND_INT_LIMITS	"Some argument is beyond int limits"

/* UTILS.C */

void	check_args(int argc, char **argv);

#endif