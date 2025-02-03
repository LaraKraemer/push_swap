/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:02:55 by lkramer           #+#    #+#             */
/*   Updated: 2025/01/31 16:37:20 by lkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 

// Declare pointers to two linked lists, one for stack 'a' and one for stack 'b'
	// set both pointer to NULL to avoid undefined behaviors and indicate we start with empty stack
// Handle input count errors. Argument count must be 2 or more. Second must not be empty. 
	// If input errors, return error
// Handle both cases of input, whether variable number of command line arguments, or as a string
	// If input of numbers is string, call split() to split the substrings 
// Initialize stack 'a' by appending each input number as a node to stack 'a'
	// handle integer overflow, duplicates, and syntax error. (e.g. input must only contain digit or -, + signs)
		// If errors found, free stack 'a', return error
	// Check each input if it is a long integer 
		// if input is a string, convert it to long integer (in order to handle larger number)
	// Append noes to stack 'a'
// Check if stack 'a' is sorted 
	// if not, implement sorting algorithm 
		// Check for 2 numbers
			// If so, simply swap numbers
		// Check for 3 numbers
			// If so, implement simple 'sort three' algorithm 
		// Check if stack has more than 3 numbers
			// If so, implement Turk algorithm  
*/
	
void print_stack(t_stack_node *stack) {
    while (stack) {
        printf("%d -> ", stack->nbr);
        stack = stack->next;
    }
    printf("NULL\n");
}

int main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1); 
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	init_stack_a(&a, argv);
	ft_printf("Stack size: %d\n", stack_size(a)); 
	if (!stack_sorted(a))
	{
		if (stack_size(a) == 2)
			swap_a(&a);
		else if (stack_size(a) == 3)
			sort_three(&a);
		else 
			sorting_turk(&a, &b);
	}
	print_stack(a);
	free_stack(&a);
}
