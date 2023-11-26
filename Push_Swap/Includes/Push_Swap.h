/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_Swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaral <gamaral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:24:53 by gamaral           #+#    #+#             */
/*   Updated: 2023/11/26 21:03:08 by gamaral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/libft.h"

/* BOOLEAN DEFINITIONS */

# define FALSE          0
# define TRUE           1

/* STD DEFINITIONS */

# define STDIN_FILENO			0
# define STDOUT_FILENO			1
# define STDERR_FILENO			2
# define END_OF_TRANSMISSION	4

/* INTEGER DEFINITIONS */

# define INT_MIN		-2147483648
# define INT_MAX		2147483647

/* ERROR DEFINITIONS */

# define ARGUMENT_IS_NOT_A_NUMBER	"Not a numeric argument"
# define DUPLICATE_ARGUMENT			"There is a duplicate argument"
# define ARGUMENT_BEYOND_INT_LIMITS	"Some argument is beyond int limits"

/* FREEING.C */

/**
 * @brief  Sets elements pointed to by "arg" to NULL
 * @param  arg: Pointer to the argument.
 * @retval None
*/
void	nulling_elements(void *arg);

/**
 * @brief  Frees all the list
 * @param  lst: Pointer to the list to be freed.
 * @retval None
*/
void	lst_free(t_list **lst);

/**
 * @brief  Frees all the array
 * @param  args: Pointer to the array to be freed.
 * @retval None
*/
void	array_free(char **args);

/* INSTRUCTIONS_OPERATE.C */

/**
 * @brief  Rotates both stack A and stack B 
 * in the same direction by the required amount.
 * @param  stack_a:   Stack A to iterate on.
 * @param  stack_b:   Stack B to iterate on.
 * @param  value:     Element value going to be operated.
 * @param  stack_sel: Char used to select which stack to operate on.
 * @retval -1
*/
int	apply_ra_rb(t_list **stack_a, t_list **stack_b, int value, char stack_sel);

/**
 * @brief  Reverse rotates both stack A and stack B 
 * in the same direction by the required amount.
 * @param  stack_a:   Stack A to iterate on.
 * @param  stack_b:   Stack B to iterate on.
 * @param  value:     Element value going to be operated.
 * @param  stack_sel: Char used to select which stack to operate on.
 * @retval -1
*/
int	apply_rra_rrb(t_list **stack_a, t_list **stack_b, int value, char stack_sel);

/**
 * @brief  Reverse rotates stack A and rotates stack B 
 * by the required amount.
 * @param  stack_a:   Stack A to iterate on.
 * @param  stack_b:   Stack B to iterate on.
 * @param  value:     Element value going to be operated.
 * @param  stack_sel: Char used to select which stack to operate on.
 * @retval -1
*/
int	apply_rra_rb(t_list **stack_a, t_list **stack_b, int value, char stack_sel);

/**
 * @brief  Rotates stack A and reverse rotate stack B 
 * by the required amount.
 * @param  stack_a:   Stack A to iterate on.
 * @param  stack_b:   Stack B to iterate on.
 * @param  value:     Element value going to be operated.
 * @param  stack_sel: Char used to select which stack to operate on.
 * @retval -1
*/
int	apply_ra_rrb(t_list **stack_a, t_list **stack_b, int value, char stack_sel);


/* INSTRUCTIONS_SWAP.C */

/**
 * @brief  Swap the first 2 elements at the top of stack A (swap a).
 * @note   Do nothing if there is only one or no elements.
 * @param  stack_a: Stack to iterate on
 * @param  print: Determines if the operation is going to be
 * printed on the screen, for checking purposes! (0 = no print, any = print)
 * @retval None
*/
void	sa(t_list **stack_a, unsigned int print);

/**
 * @brief  Swap the first 2 elements at the top of stack B (swap b).
 * @note   Do nothing if there is only one or no elements.
 * @param  stack_b: Stack to iterate on
 * @param  print: Determines if the operation is going to be
 * printed on the screen, for checking purposes! (0 = no print, any = print)
 * @retval None
*/
void	sb(t_list **stack_b, unsigned int print);

/**
 * @brief  Swap the first 2 elements at the top of stack A
 * And does the same for stack B (swap a and swap b).
 * @note   Do nothing if there is only one or no elements
 * in the stack.
 * @param  stack_a: Stack A to iterate on
 * @param  stack_b: Stack B to iterate on
 * @param  print: Determines if the operation is going to be
 * printed on the screen, for checking purposes! (0 = no print, any = print)
 * @retval None
*/
void	ss(t_list **stack_a, t_list **stack_b, unsigned int print);

/* INSTRUCTIONS_PUSH */

/**
 * @brief  Take the first element at the top of B 
 * and put it at the top of stack A (push a).
 * @note   Do nothing if B is empty.
 * @param  stack_a: Stack A to iterate on
 * @param  stack_b: Stack B to iterate on
 * @param  print: Determines if the operation is going to be
 * printed on the screen, for checking purposes! (0 = no print, any = print)
 * @retval None
*/
void	pa(t_list **stack_a, t_list **stack_b, unsigned int print);

/**
 * @brief  Take the first element at the top of A 
 * and put it at the top of stack B (push b).
 * @note   Do nothing if A is empty.
 * @param  stack_b: Stack B to iterate on
 * @param  stack_a: Stack A to iterate on
 * @param  print: Determines if the operation is going to be
 * printed on the screen, for checking purposes! (0 = no print, any = print)
 * @retval None
*/
void	pb(t_list **stack_b, t_list **stack_a, unsigned int print);

/* INSTRUCTIONS_ROTATE.C */

/**
 * @brief  Shift up all elements of stack A by 1 (rotate a).
 * @note   The first element becomes the last one.
 * @param  stack_a: Stack to iterate on
 * @param  print: Determines if the operation is going to be
 * printed on the screen, for checking purposes! (0 = no print, any = print)
 * @retval None
*/
void	ra(t_list **stack_a, unsigned int print);

/**
 * @brief  Shift up all elements of stack B by 1 (rotate b).
 * @note   The first element becomes the last one.
 * @param  stack_b: Stack to iterate on
 * @param  print: Determines if the operation is going to be
 * printed on the screen, for checking purposes! (0 = no print, any = print)
 * @retval None
*/
void	rb(t_list **stack_b, unsigned int print);

/**
 * @brief  Shift up all elements of stack A and B by 1
 * (rotate a and rotate b).
 * @note   The first element becomes the last one.
 * @param  stack_a: Stack A to iterate on
 * @param  stack_b: Stack B to iterate on
 * @param  print: Determines if the operation is going to be
 * printed on the screen, for checking purposes! (0 = no print, any = print)
 * @retval None
*/
void	rr(t_list **stack_a, t_list **stack_b, unsigned int print);

/* INSTRUCTIONS_REVERSE_ROTATE */

/**
 * @brief  Shift down all elements of stack A by 1 
 * (reverse rotate a).
 * @note   The last element becomes the first one.
 * @param  stack_a: Stack to iterate on
 * @param  print: Determines if the operation is going to be
 * printed on the screen, for checking purposes! (0 = no print, any = print)
 * @retval None
*/
void	rra(t_list **stack_a, unsigned int print);

/**
 * @brief  Shift down all elements of stack B by 1 
 * (reverse rotate b).
 * @note   The last element becomes the first one.
 * @param  stack_b: Stack to iterate on
 * @param  print: Determines if the operation is going to be
 * printed on the screen, for checking purposes! (0 = no print, any = print)
 * @retval None
*/
void	rrb(t_list **stack_b, unsigned int print);

/**
 * @brief  Shift down all elements of stack A and B by 1 
 * (reverse rotate a and reverse rotate b).
 * @note   The last element becomes the first one.
 * @param  stack_a: Stack to iterate on
 * @param  stack_b: Stack to iterate on
 * @param  print: Determines if the operation is going to be
 * printed on the screen, for checking purposes! (0 = no print, any = print)
 * @retval None
*/
void	rrr(t_list **stack_a, t_list **stack_b, unsigned int print);

/* SORTING.C */

/**
 * @brief  Sorts the stack when it has three elements.
 * @param  stack_a: Stack to sort.
 * @retval None
*/
void	sort_three_elements(t_list **stack_a);

/**
 * @brief  Sorts B stack up to three elements.
 * @param  stack_a: Stacks to iterate on.
 * @param  stack_b: Stacks to iterate on.
 * @retval None
*/
void	sort_b_to_three(t_list **stack_a, t_list **stack_b);

/**
 * @brief  Pushes all elements from Stack A to Stack B, until
 * Stack A has only three elements left; sorts the remaining 
 * three elements of A and also sorts B stack.
 * @param  stack_a: Stacks to iterate on.
 * @param  stack_b: Stacks to iterate on.
 * @retval None
*/
void	sort_b(t_list **stack_a, t_list **stack_b);

/**
 * @brief  Pushes back elements from Stack B to Stack A
 * and finishes sorting stack A with a few operations left.
 * @param  stack_a: Stacks to iterate on.
 * @param  stack_b: Stacks to iterate on.
 * @retval None
*/
void	sort_a(t_list **stack_a, t_list **stack_b);

/**
 * @brief  Sorts the stack, making all operations needed.
 * @param  stack_a: Stack to iterate on.
 * @param  stack_b: Stack to iterate on.
 * @retval None
*/
void	sort_stack(t_list **stack_a, t_list **stack_b);

/* UTILS.C */

/**
 * @brief  Handle error situations.
 * @param  argc: Total number of arguments
 * @param  argv: Array of arguments
 * @param  error: Error message
 * @retval None
*/
void	handle_error(int argc, char **argv, char *error);

/**
 * @brief  Checks if all arguments are in accordance to 
 * the program requirements.
 * @param  argc: Total number of arguments
 * @param  argv: Array of arguments
 * @retval None
*/
void	check_args(int argc, char **argv);

/**
 * @brief  Checks if the stack is already sorted in 
 * ascending order.
 * @param  stack: Stack to be iterated and verified.
 * @retval None
*/
int		is_sorted(t_list **stack);

/* UTILS_2.C */

/**
 * @brief  Finds the element index in the current list
 * @param list_head: List head (first element of the list)
 * @param value: Content value to search for in the list
 * @retval Index of the element (list position)
*/
int	ft_lst_find_index_ps(t_list *list_head, int value);

/**
 * @brief  Finds the max value from all elements within
 * the list.
 * @param  stack: Stack to be iterated and verified.
 * @retval Max int value within the list
*/
int	get_max_value(t_list **stack);

/**
 * @brief  Finds the min value from all elements within
 * the list.
 * @param  stack: Stack to be iterated and verified.
 * @retval Min int value within the list
*/
int	get_min_value(t_list **stack);

/**
 * @brief  Finds the correct index to place the value in stack B.
 * @note   It checks what index number push_value will get 
 * after being pushed to stack B.
 * @param  head_b: Element on top of the stack B.
 * @param  push_value: Element int value.
 * @retval Returns the correct index in which push_value should 
 * be placed.
*/
int	find_place_in_b(t_list *head_b, int push_value);

/**
 * @brief  Finds the correct index to place the value in stack A.
 * @note   It checks what index number push_value will get 
 * after being pushed to stack A.
 * @param  head_a: Element on top of the stack A.
 * @param  push_value: Element int value.
 * @retval Returns the correct index in which push_value should 
 * be placed.
*/
int	find_place_in_a(t_list *head_a, int push_value);

/* ROTATION_CALCULUS_A.C */

/**
 * @brief  Calculates how many times we should 
 * rotate the stacks together (ra + rb case).
 * @note   The logic on stack A is: the higher value
 * element should be at bottom, pushing the cheapest 
 * cost element to stack B, in order to be sorted.
 * @param  head_a: Element on top of the stack A.
 * @param  head_b: Element on top of the stack B.
 * @retval The least number of operations needed 
 * in order to put the next element available to push.
*/
int	ft_case_rarb_a(t_list *head_a, t_list *head_b, int value);

/**
 * @brief  Calculates how many times we should 
 * rotate the stacks together (rra + rrb case).
 * @note   The logic on stack A is: the higher value
 * element should be at bottom, pushing the cheapest 
 * cost element to stack B, in order to be sorted.
 * @param  head_a: Element on top of the stack A.
 * @param  head_b: Element on top of the stack B.
 * @retval The least number of operations needed 
 * in order to put the next element available to push.
*/
int	ft_case_rrarrb_a(t_list *head_a, t_list *head_b, int value);

/**
 * @brief  Calculates how many times we should 
 * rotate the stacks together (ra + rrb case).
 * @note   The logic on stack A is: the higher value
 * element should be at bottom, pushing the cheapest 
 * cost element to stack B, in order to be sorted.
 * @param  head_a: Element on top of the stack A.
 * @param  head_b: Element on top of the stack B.
 * @retval The least number of operations needed 
 * in order to put the next element available to push.
*/
int	ft_case_rarrb_a(t_list *head_a, t_list *head_b, int value);

/**
 * @brief  Calculates how many times we should 
 * rotate the stacks together (rra + rb case).
 * @note   The logic on stack A is: the higher value
 * element should be at bottom, pushing the cheapest 
 * cost element to stack B, in order to be sorted.
 * @param  head_a: Element on top of the stack A.
 * @param  head_b: Element on top of the stack B.
 * @retval The least number of operations needed 
 * in order to put the next element available to push.
*/
int	ft_case_rrarb_a(t_list *head_a, t_list *head_b, int value);

/* ROTATION_CALCULUS_B.C */

/**
 * @brief  Calculates how many times we should 
 * rotate the stacks together (ra + rb case).
 * @note   The logic on stack B is: the higher value
 * element should be on top, since when pushed back to A,
 * it will be on the bottom.
 * @param  head_a: Element on top of the stack A.
 * @param  head_b: Element on top of the stack B.
 * @retval The least number of operations needed 
 * in order to put the next element available to push.
*/
int	ft_case_rarb(t_list *head_a, t_list *head_b, int value);

/**
 * @brief  Calculates how many times we should 
 * rotate the stacks together (rra + rrb case).
 * @note   The logic on stack B is: the higher value
 * element should be on top, since when pushed back to A,
 * it will be on the bottom.
 * @note   Since here we have reverse rotate,rather than index number, 
 * we check reverse index number which is calculated by 
 * list_size - index_number.
 * @param  head_a: Element on top of the stack A.
 * @param  head_b: Element on top of the stack B.
 * @retval The least number of operations needed 
 * in order to put the next element available to push.
*/
int	ft_case_rrarrb(t_list *head_a, t_list *head_b, int value);

/**
 * @brief  Calculates how many times we should 
 * rotate the stacks together (rra + rb case).
 * @note   The logic on stack B is: the higher value
 * element should be on top, since when pushed back to A,
 * it will be on the bottom.
 * @param  head_a: Element on top of the stack A.
 * @param  head_b: Element on top of the stack B.
 * @retval The least number of operations needed 
 * in order to put the next element available to push.
*/
int	ft_case_rrarb(t_list *head_a, t_list *head_b, int value);

/**
 * @brief  Calculates how many times we should 
 * rotate the stacks together (ra + rrb case).
 * @note   The logic on stack B is: the higher value
 * element should be on top, since when pushed back to A,
 * it will be on the bottom.
 * @param  head_a: Element on top of the stack A.
 * @param  head_b: Element on top of the stack B.
 * @retval The least number of operations needed 
 * in order to put the next element available to push.
*/
int	ft_case_rarrb(t_list *head_a, t_list *head_b, int value);

/* ROTATION_NEEDS */

/**
 * @brief  Calculates and decides which rotation 
 * combination is the best to use, least operation cost
 * to sort the stack. Function is used during push from A to B.
 * @param  head_a: Element on top of the stack A.
 * @param  head_b: Element on top of the stack B.
 * @retval The least number of operations needed 
 * in order to put the next element available to push.
*/
int	rotate_needs_a_to_b(t_list *head_a, t_list *head_b);

/**
 * @brief  Calculates and decides which rotation 
 * combination is the best to use, least operation cost
 * to sort the stack. Function is used during push from B to A.
 * @param  head_a: Element on top of the stack A.
 * @param  head_b: Element on top of the stack B.
 * @retval The least number of operations needed 
 * in order to put the next element available to push.
*/
int	rotate_needs_b_to_a(t_list *head_a, t_list *head_b);

/* COMANDO PARA COMPILACAO E TESTES */

/* BONUS FILES -> CHECKER */

/* CHECKER_UTILS.C */

/**
 * @brief  Prints the message contained in error string 
 * on the standard error
 * @param  error: Error string message to be printed
 * @retval None
*/
void	handle_error_checker(t_list **stack_a, t_list **stack_b, char *error);

/**
 * @brief  Checks for each input line, verifying if it is an allowed
 * operation and executing the operation
 * @param  stack_a:   Stack A in which operations will be performed
 * @param  stack_b:   Stack B in which operations will be performed
 * @param  operation: Operation to be checked and performed, if allowed
 * @retval None
*/
void	compare_input_operation(t_list **stack_a, t_list **stack_b, char *operation);

/**
 * @brief  Checks for each operation, verifying if it is an allowed operation, 
 * executing the operation and checking if it sorts the stack correctly
 * @param  stack_a: Stack A in which operations will be performed
 * @param  stack_b: Stack B in which operations will be performed
 * @param  input:   Operation to be checked and performed, if allowed
 * @retval None
*/
void	check_operation_input(t_list **stack_a, t_list **stack_b, char *input);

/**
 * @brief  Initializes the stacks with the arguments passed to the program.
 * @param  argc:  Ammount of arguments inserted in the program.
 * @param  argv:  List of arguments inserted in the program.
 * @param  stack: Stack to be initialized with the arguments.
 * @retval None
*/
void	init_checker_stack(t_list **stack, int argc, char **argv);

// cd Libft && make bonus && cd .. && cc -c -Wall -Wextra -Werror Src/* && cc -Wall -Wextra -Werror *.o main.c -L Libft -l ft -o push_swap && cd Libft && make fclean && cd ..

#endif