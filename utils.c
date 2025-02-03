/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:57:48 by lkramer           #+#    #+#             */
/*   Updated: 2025/01/31 16:20:23 by lkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Returns 0 when sorted and 1 if not */
bool stack_sorted(t_stack_node *a)
{
    if (!a)
        return (true); 
    while (a->next)
    {
		printf("Comparing %d and %d\n", a->nbr, a->next->nbr);
        if (a->nbr > a->next->nbr)
		{
			printf("Stack is NOT sorted!\n");
            return (false);
		}
        a = a->next;
    }
	printf("Stack is already sorted.\n");
    return (true);
}

/* Returns the number of node in the stack */
int stack_size(t_stack_node *a)
{
    int size;
	
	size = 0;
    while (a)
    {
        size++;
        a = a->next;
    }
    return (size);
}
/* Retuns biggest node in stack */
t_stack_node	*find_max_node(t_stack_node *stack)
{
    if (!stack)
        return (NULL);
    long			biggest;
	t_stack_node	*max_node;
	
	biggest = LONG_MIN;
    while (stack)
    {
        if (stack->nbr > biggest)
		{
            biggest = stack->nbr;
			max_node = stack;
		}
        stack = stack->next;
    }
    return (max_node);
}
/* Returns smallest node in stack */
t_stack_node	*find_min_node(t_stack_node *stack)
{
    if (!stack)
        return (NULL);
	long			smallest;
	t_stack_node	*min_node;

	smallest = LONG_MAX;
    while (stack)
    {
        if (stack->nbr < smallest)
		{
            smallest = stack->nbr;
			min_node = stack;
		}
        stack = stack->next;
    }
    return (min_node);
}

/* Returns a pointers to the last node in stack */
t_stack_node	*find_last_node(t_stack_node *stack) 
{
	if (!stack)
		return (NULL);
	while (stack->next) 
		stack = stack->next;
	return (stack);
}
