/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes_b_to_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:52:52 by lkramer           #+#    #+#             */
/*   Updated: 2025/01/31 16:12:57 by lkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


/* Loop through every node in b to find 
target node for a */
static void	find_target_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*cur_a;
	t_stack_node	*target_node_to_push;
	long			best_index;

	while (b)
	{
		best_index = LONG_MAX;
		cur_a = a;
		while (cur_a)
		{
			if (cur_a->nbr < b->nbr 
					&& cur_a->nbr > best_index)
			{
				best_index = cur_a->nbr;
				target_node_to_push = cur_a;
			}
			cur_a = cur_a->next;
		}
		if (best_index == LONG_MAX)
			b->target_node = find_min_node(a);
		else
			b->target_node = target_node_to_push;
		b = b->next;
	}
}

void init_nodes_b(t_stack_node *a, t_stack_node *b)
{
    cur_index(a);
    cur_index(b);
    find_target_b(a, b);
    push_cost(a, b);
    find_cheapest(b);
}
