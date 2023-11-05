/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_Swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:24:53 by gamaral           #+#    #+#             */
/*   Updated: 2023/11/05 17:19:23 by gamaral          ###   ########.fr       */
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

/* FREEING.C */

void	nulling_elements(void *arg);
void	lst_free(t_list **lst);
void	array_free(char **args);

/* INSTRUCTIONS_SWAP.C */

/**
 * @brief  Swap the first 2 elements at the top of stack A (swap a).
 * @note   Do nothing if there is only one or no elements.
 * @param  stack_a: Stack to iterate on
 * @retval None
*/
void	sa(t_list **stack_a);

/**
 * @brief  Swap the first 2 elements at the top of stack B (swap b).
 * @note   Do nothing if there is only one or no elements.
 * @param  stack_b: Stack to iterate on
 * @retval None
*/
void	sb(t_list **stack_b);

/**
 * @brief  Swap the first 2 elements at the top of stack A
 * And does the same for stack B (swap a and swap b).
 * @note   Do nothing if there is only one or no elements
 * in the stack.
 * @param  stack_a: Stack A to iterate on
 * @param  stack_b: Stack B to iterate on
 * @retval None
*/
void	ss(t_list **stack_a, t_list **stack_b);

/* INSTRUCTIONS_PUSH */

/**
 * @brief  Take the first element at the top of B 
 * and put it at the top of stack A (push a).
 * @note   Do nothing if B is empty.
 * @param  stack_a: Stack A to iterate on
 * @param  stack_b: Stack B to iterate on
 * @retval None
*/
void	pa(t_list **stack_a, t_list **stack_b);

/**
 * @brief  Take the first element at the top of A 
 * and put it at the top of stack B (push b).
 * @note   Do nothing if A is empty.
 * @param  stack_b: Stack B to iterate on
 * @param  stack_a: Stack A to iterate on
 * @retval None
*/
void	pb(t_list **stack_b, t_list **stack_a);

/* INSTRUCTIONS_ROTATE.C */

/**
 * @brief  Shift up all elements of stack A by 1 (rotate a).
 * @note   The first element becomes the last one.
 * @param  stack_a: Stack to iterate on
 * @retval None
*/
void	ra(t_list **stack_a);

/**
 * @brief  Shift up all elements of stack B by 1 (rotate b).
 * @note   The first element becomes the last one.
 * @param  stack_b: Stack to iterate on
 * @retval None
*/
void	rb(t_list **stack_b);

/**
 * @brief  Shift up all elements of stack A and B by 1
 * (rotate a and rotate b).
 * @note   The first element becomes the last one.
 * @param  stack_a: Stack A to iterate on
 * @param  stack_b: Stack B to iterate on
 * @retval None
*/
void	rr(t_list **stack_a, t_list **stack_b);

/* INSTRUCTIONS_REVERSE_ROTATE */

/**
 * @brief  Shift down all elements of stack A by 1 
 * (reverse rotate a).
 * @note   The last element becomes the first one.
 * @param  stack_a: Stack to iterate on
 * @retval None
*/
void	rra(t_list **stack_a);

/**
 * @brief  Shift down all elements of stack B by 1 
 * (reverse rotate b).
 * @note   The last element becomes the first one.
 * @param  stack_b: Stack to iterate on
 * @retval None
*/
void	rrb(t_list **stack_b);

/**
 * @brief  Shift down all elements of stack A and B by 1 
 * (reverse rotate a and reverse rotate b).
 * @note   The last element becomes the first one.
 * @param  stack_a: Stack to iterate on
 * @param  stack_b: Stack to iterate on
 * @retval None
*/
void	rrr(t_list **stack_a, t_list **stack_b);

/* SORTING.C */

void	sort_stack(t_list **stack_a, t_list **stack_b);

/* UTILS.C */

void	handle_error(int argc, char **argv, char *error);
void	check_args(int argc, char **argv);
int		is_sorted(t_list **stack);

#endif