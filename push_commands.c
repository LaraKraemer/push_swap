/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:50:25 by lkramer           #+#    #+#             */
/*   Updated: 2025/01/31 17:22:35 by lkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	 push_command(t_stack_node **dest_stack, t_stack_node **src_stack)
{
	t_stack_node	*node_to_push;
	
	if(!*src_stack)
	{
		ft_printf("empty src\n");
		return ;
	}
	node_to_push = *src_stack;
	*src_stack = (*src_stack)->next;
	if (*src_stack)
   		printf("New top of src_stack: %d\n", (*src_stack)->nbr);
	else
    	printf("src_stack is now empty\n");
	node_to_push->next = *dest_stack;
	*dest_stack = node_to_push;
	printf("Pushed node: %d to stack B\n", node_to_push->nbr);
}

/* Pushes first node from stack b to top of 
stack a  */
void push_a(t_stack_node **a, t_stack_node **b)
{
    push_command(a, b);
	ft_printf("pa\n");
}

/* Pushes first node from stack a to top 
of stack b */
void push_b(t_stack_node **b, t_stack_node **a)
{
	push_command(b, a);
	ft_printf("pb\n");
} 