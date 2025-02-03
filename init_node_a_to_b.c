/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_node_a_to_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:52:40 by lkramer           #+#    #+#             */
/*   Updated: 2025/01/31 16:05:09 by lkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cur_index(t_stack_node *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stack_size(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i < median)
			stack->above_median = true;
			else 
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
}
/* Loop through every node in b to find 
target node for a */
static void	find_target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*cur_b;
	t_stack_node	*target_node_to_push;
	long			best_index;

	while (a)
	{
		best_index = LONG_MIN;
		cur_b = b;
		while (cur_b)
		{
			if (cur_b->nbr < a->nbr 
					&& cur_b->nbr > best_index)
			{
				best_index = cur_b->nbr;
				target_node_to_push = cur_b;
			}
			cur_b = cur_b->next;
		}
		if (best_index == LONG_MIN)
			a->target_node = find_max_node(b);
		else 
			a->target_node = target_node_to_push;
		a = a->next;
	}
}
/* Sum of amount of rotation it takes for a to be on top
amount of rotation it takes target not to be on top */
void	push_cost(t_stack_node *a, t_stack_node *b)
{
	int	size_a;
	int	size_b;
	
	size_a = stack_size(a);
	size_b = stack_size(b);
	while (a)
	{
		a->push_cost =a->index;
		printf("Push cost for node %d: %d\n", a->nbr, a->push_cost);
		if (!(a->above_median))
		{
			a->push_cost = size_a - (a->index);
			if (a->target_node->above_median)
				a->push_cost += a->target_node->index;
			else
				a->push_cost += size_b - (a->target_node->index);
		}
		else
        {
            printf("push_cost: Warning! a->target_node is NULL for node %d\n", a->nbr);
        }
        printf("Push cost (after adjustment) for node %d: %d\n", a->nbr, a->push_cost);
		a = a->next;
	}
	
}
/* Based on push cost, loops through nodes 
and find nodes with lowest push cost. Set
 */
void	find_cheapest(t_stack_node *stack)
{
	long			cheapest_value;
	t_stack_node	*node_with_fewest_rotation;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		printf("Cheapest node: %d\n", node_with_fewest_rotation->nbr);
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			node_with_fewest_rotation = stack;
		}
		stack = stack->next;
	}
	printf("Cheapest node: %d\n", node_with_fewest_rotation->nbr);

	node_with_fewest_rotation->cheapest = true;
}

/* call preperation functions */
void init_nodes_a(t_stack_node *a, t_stack_node *b)
{
	cur_index(a);
	cur_index(b);
	find_target_a(a, b);
	push_cost(a, b);
	find_cheapest(a);
}

