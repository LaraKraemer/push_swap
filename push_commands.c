/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:50:25 by lkramer           #+#    #+#             */
/*   Updated: 2025/02/05 21:28:39 by lkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* first element becomes the last element.*/
void rotate_a(t_stack_node **a)
{
	if (!(*a) || !(*a)->next)
		return;
	t_stack_node *first;
	t_stack_node *last;
	
	first = *a;
	last = *a;
    while (last->next)
        last = last->next;
    *a = (*a)->next;
	last->next = first; 
    first->next = NULL;
	ft_printf("ra\n");
}

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

/* Swap first two nodes in stack a */
void swap_a(t_stack_node **a)
{
	int temp;
    if (!(*a) || !(*a)->next)
        return; 
	
    temp = (*a)->nbr;
    (*a)->nbr = (*a)->next->nbr;
    (*a)->next->nbr = temp;
	ft_printf("sa\n");
}

/* Pushes first node from stack b to top of 
stack a  */
void push_a(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*temp;
	
	if (*b)
	{
		temp = *b;
		*b = (*b)->next;
		temp->next = *a;
		*a = temp;
	}
	ft_printf("pa\n");
}
/* Pushes first node from stack a to top 
of stack b */
void push_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*temp;
	if (*a)
	{
		temp = *a;
		*a = (*a)->next;
		temp->next = *b;
		*b = temp;		
	}
	ft_printf("pb\n");	
} 
