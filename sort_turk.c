/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:05:26 by lkramer           #+#    #+#             */
/*   Updated: 2025/01/31 16:56:07 by lkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_stack_node **a,
						t_stack_node **b,
						t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node
		&& *a != cheapest_node)
		rotate_rr(a, b);
	cur_index(*a);
	cur_index(*b);
}

static void	rev_rotate_both(t_stack_node **a,
								t_stack_node **b,
								t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node
		&& *a != cheapest_node) 
		reverse_rotate_rr(a, b); 
	cur_index(*a);
	cur_index(*b);
}


static void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*best_node;
	
	best_node = return_best_node(*a);
	if (best_node->above_median && 
				best_node->target_node->above_median)
		rotate_both(a, b, best_node);
	else if (!(best_node->above_median) && 
				!(best_node->target_node->above_median))
		rev_rotate_both(a, b, best_node);
	move_node_to_top(a, best_node, 'a');
	move_node_to_top(a, best_node->target_node, 'b');
	push_b(b, a);
}

static void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	move_node_to_top(a, (*b)->target_node, 'a');
	push_a(a, b);
	
}


static void	check_min_on_top(t_stack_node **a)
{
	while((*a)->nbr != find_min_node(*a)->nbr)
	{
		if(find_min_node(*a)->above_median)
			rotate_a(a);
		else
			reverse_rotate_a(a);
	}
}

void sorting_turk(t_stack_node **a, t_stack_node **b)
{
	int size_a;
	 
	size_a = stack_size(*a);
	if (size_a-- > 3 && !stack_sorted(*a))
	{
		printf("Condition met, calling push_b\n");
	 	push_b(b, a);
	}
	printf("Stack A size: %d\n", stack_size(*a));
	printf("Stack B size: %d\n", stack_size(*b));
	if (size_a-- > 3 && !stack_sorted(*a))
	{
		printf("Condition met again, calling push_b\n");
	 	push_b(b, a);
	}
	while (size_a-- > 3 && !stack_sorted(*a))
	{
		printf("Initializing Nodes A\n"); // Debugging
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	ft_printf("CHECK\n");
	while(*b)
	{
		printf("Initializing Nodes B\n"); // Debugging
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	cur_index(*a);
	printf("final\n");
	check_min_on_top(a);
}
