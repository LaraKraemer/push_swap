/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:49:28 by lkramer           #+#    #+#             */
/*   Updated: 2025/01/30 11:16:56 by lkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* last element becomes the first.
 */
void reverse_rotate_a(t_stack_node **a)
{
    if (!(*a) || !(*a)->next) 
        return;

    t_stack_node *second_last;
	t_stack_node *last;
	
	second_last = NULL;
	last = *a;

    while (last->next)
    {
        second_last = last;
        last = last->next;
    }
    second_last->next = NULL;
    last->next = *a;
    *a = last;
	ft_printf("rra\n");
}

/* last element becomes the first.
 */
void reverse_rotate_b(t_stack_node **b)
{
    if (!(*b) || !(*b)->next) 
        return;

    t_stack_node *second_last;
	t_stack_node *last;
	
	second_last = NULL;
	last = *b;

    while (last->next)
    {
        second_last = last;
        last = last->next;
    }

    second_last->next = NULL;
    last->next = *b;
    *b = last;
	ft_printf("rrb\n");
}
/* last element becomes first one in stack a and b */
void reverse_rotate_rr(t_stack_node **a, t_stack_node **b)
{
	reverse_rotate_a(a);
	reverse_rotate_b(b);
	ft_printf("rrr\n");
}