/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:57:48 by lkramer           #+#    #+#             */
/*   Updated: 2025/02/05 21:24:24 by lkramer          ###   ########.fr       */
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
        if (a->nbr > a->next->nbr)
			return (false);
        a = a->next;
    }
    return (true);
}

/* Returns the number of node in the stack */
int	stack_size(t_stack_node *a)
{
	int	size;
	
	size = 0;
	while (a)
	{
		size++;
		a = a->next;
	}
	return (size);
}
/* Returns smallest node in stack */
t_stack_node	*find_min_node(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	long			smallest;
	t_stack_node	*min_node;

	min_node = NULL;
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
