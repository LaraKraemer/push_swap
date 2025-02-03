/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:21:10 by lkramer           #+#    #+#             */
/*   Updated: 2025/01/30 12:42:56 by lkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_two(t_stack_node **a)
{
    if ((*a)->nbr > (*a)->next->nbr)
        swap_a(a); 
}

void sort_three(t_stack_node **a)
{
    int first;
    int second;
    int third;
    
    first = (*a)->nbr;
    second = (*a)->next->nbr;
    third = (*a)->next->next->nbr;
    if (first < second && second < third)
        return;
    /* Case: (3, 2, 1) -> Swap first two, then reverse rotate */
    if (first > second && second > third)
	{
        swap_a(a);
        reverse_rotate_a(a);
    }
    /* Case: (3, 1, 2) -> Rotate */
    else if (first > second && second < third && first > third)
        rotate_a(a);
	/* Case: (2, 3, 1) -> Swap first two, then rotate*/
	else if (first < second && second > third && first < third)
	{
        swap_a(a);
        rotate_a(a);
    }
    /* Case: (2, 4, 1) -> Reverse rotate */
    else if (first < second && second > third && first > third)
        reverse_rotate_a(a);
    /* Case: (3, 2, 1) -> Swap first two */
    else if (first > second && second < third)
        swap_a(a);
}
