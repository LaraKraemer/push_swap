/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:02:55 by lkramer           #+#    #+#             */
/*   Updated: 2025/02/05 21:51:20 by lkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
	
int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	int				is_split;
	
	is_split = 0; 
	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1); 
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		is_split = 1; 
	}
	init_stack_a(&a, argv, is_split);
	if (!stack_sorted(a))
	{
		check_stack_size(&a, &b);
	}
	free_stack(&a);
}

void check_stack_size(t_stack_node **a, t_stack_node **b)
{
	if (stack_size(*a) == 2)
		swap_a(a);
	else if (stack_size(*a) == 3)
		sort_three(a);
	else if (stack_size(*a) <= 5)
		sort_four_five(a, b);
	else
		radix_sort(a, b);
}
