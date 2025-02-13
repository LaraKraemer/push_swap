/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:03:05 by lkramer           #+#    #+#             */
/*   Updated: 2025/02/07 13:41:31 by lkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Calculates max number of bits required to represent 
highest index value in the stack.
*/
int	get_max_bits(t_stack_node *stack)
{
	int	max_index;
	int	max_bits;

	max_index = 0;
	max_bits = 0;
	while (stack)
	{
		if (stack->index > max_index)
			max_index = stack->index;
		stack = stack->next;
	}
	while ((max_index >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

/* 
Initializes index of every node in 
stack to -1, marking them as unindexed.
helps when setting indices for sorting later.
*/
void	initialize_indices(t_stack_node *stack)
{
	t_stack_node	*current;

	current = stack;
	while (current)
	{
		current->index = -1;
		current = current->next;
	}
}

/* 
Finds & returns node with smallest value that has not been 
indexed yet, helps assigning indices by 
selecting the smallest unindexed node.
 */
t_stack_node	*find_min_unindexed(t_stack_node *stack)
{
	t_stack_node	*current;
	t_stack_node	*min_node;
	int				min;

	current = stack;
	min_node = NULL;
	min = INT_MAX;
	while (current)
	{
		if (current->index == -1 && current->nbr < min)
		{
			min = current->nbr;
			min_node = current;
		}
		current = current->next;
	}
	return (min_node);
}

/* 
Assigns index to each node in the stack, based on values,
finds the smallest unindexed node, assigns it an index, 
repeats until all nodes are indexed
 */
void	assign_indices(t_stack_node *stack)
{
	int				size;
	int				i;
	t_stack_node	*min_node;

	i = 0;
	size = stack_size(stack);
	initialize_indices(stack);
	while (i < size)
	{
		min_node = find_min_unindexed(stack);
		if (min_node)
			min_node->index = i;
		i++;
	}
}

/* 
Sorts stack based on bits of the index value,
iterates through each bit of the indices and 
moves elements between two stacks based on the bit value.
 */
void	radix_sort(t_stack_node **a, t_stack_node **b)
{
	int	max_bits;
	int	i;
	int	size;
	int	j;

	assign_indices(*a);
	size = stack_size(*a);
	max_bits = get_max_bits(*a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*a)->index >> i) & 1) == 1)
				rotate_a(a);
			else
				push_b(a, b);
			j++;
		}
		while (*b)
			push_a(a, b);
		i++;
	}
}
