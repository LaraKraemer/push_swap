/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:48:51 by lkramer           #+#    #+#             */
/*   Updated: 2025/01/30 11:17:56 by lkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* first element becomes the last element.*/
void rotate_a(t_stack_node **a)
{
    if (!(*a) || !(*a)->next)
        return;

    t_stack_node *temp;
	t_stack_node *last;
	
	temp = *a;
    *a = (*a)->next;
    last = *a;
    while (last->next)
        last = last->next;
    last->next = temp; 
    temp->next = NULL;
	ft_printf("ra\n");
}

/* first element becomes the last element. */
void rotate_b(t_stack_node **b)
{
	if (!(*b) || !((*b)->next))
		return;

	t_stack_node *temp;
	t_stack_node *last;
	
	temp = *b;
	*b = (*b)->next;
	last = *b;
	while(last->next)
		last = last->next;
	last->next = temp;
	temp->next = NULL;
	ft_printf("rb\n");
}
/* first element becomes the last element in both stacks */
void rotate_rr(t_stack_node **a, t_stack_node **b)
{
    rotate_a(a);
    rotate_b(b);
	ft_printf("rr\n");
}
