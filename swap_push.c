/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:37:47 by lkramer           #+#    #+#             */
/*   Updated: 2025/01/31 14:28:21 by lkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Swap first two nodes in stack a */
void swap_a(t_stack_node **a)
{
    if (!(*a) || !(*a)->next)
        return; 
	int temp;
	
    temp = (*a)->nbr;
    (*a)->nbr = (*a)->next->nbr;
    (*a)->next->nbr = temp;
	printf("sa\n");
}

/* Swap first two nodes in stack b */
void swap_b(t_stack_node **b)
{
    if (!(*b) || !(*b)->next)
        return; 
	int temp;
	
    temp = (*b)->nbr;
    (*b)->nbr = (*b)->next->nbr;
    (*b)->next->nbr = temp;
	ft_printf("sb\n");
}
/* Swap stack a and stack b at the same */
void swap_ss(t_stack_node **a, t_stack_node **b)
{
    swap_a(a); 
    swap_b(b); 
	ft_printf("ss\n");
}
