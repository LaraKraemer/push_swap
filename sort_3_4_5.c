/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_4_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:21:10 by lkramer           #+#    #+#             */
/*   Updated: 2025/02/05 21:55:45 by lkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three(t_stack_node **a)
{
    int first;
    int second;
    int third;
    
    first = (*a)->nbr;
    second = (*a)->next->nbr;
    third = (*a)->next->next->nbr;
    if (stack_sorted(*a))
        return ;
	if (first > second && second > third && first > third)
	{
		rotate_a(a);
		swap_a(a);
	}
	else if (first > second && second < third && first > third)
		rotate_a(a);
	else if (first > second && second < third)
		swap_a(a);
	else if (first < second && second > third && first < third)
	{
		reverse_rotate_a(a);
		swap_a(a);
	}
	else if (first < second && second > third && first > third)
		reverse_rotate_a(a);
}

void sort_four_five(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*min_node;
	int				min_value;

	min_node = find_min_node(*a);
    min_value = min_node->nbr;
	if (stack_size(*a) == 5 && (*a)->next->next->next->next->nbr == min_value)
    	reverse_rotate_a(a);
	while ((*a)->nbr != min_value)
		rotate_a(a);
    push_b(a, b);
	if ((stack_size(*a) > 3))
	{
		min_node = find_min_node(*a);
    	while ((*a)->nbr != min_node->nbr)
        	rotate_a(a);
		push_b(a, b);
	}
	sort_three(a);
	while (*b)
        push_a(a, b);
}
