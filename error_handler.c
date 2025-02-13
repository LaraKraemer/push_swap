/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:01:43 by lkramer           #+#    #+#             */
/*   Updated: 2025/02/11 11:28:29 by lkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Checks for syntax errors. Checks if argument/s include anything besides 
+, - or digits. Returns 1 for syntax error */
int	error_syntax(char *str_num)
{
	if (!str_num || !str_num[0])
		return (1);
	if (str_num[0] == '+' || str_num[0] == '-')
		str_num++;
	while (*str_num)
	{
		if (!ft_isdigit(*str_num))
			return (1);
		++str_num;
	}
	return (0);
}

/* Checks duplications errors. Checks if argument/s are duplicates.
Returns 1 for duplications error */
int	error_dup(t_stack_node *a, int num)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nbr == num)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_array(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*temp_node;
	t_stack_node	*current;

	if (!stack || !(*stack))
		return ;
	current = *stack;
	while (current)
	{
		temp_node = current->next;
		free(current);
		current = temp_node;
	}
	*stack = NULL;
}

/* Calls free_stack functions and prints on stdout a Error message, 
then exits program*/
void	free_errors(t_stack_node **a, char **argv, int is_split)
{
	if (a && *a)
		free_stack(a);
	if (is_split)
		free_array(argv);
	write(2, "Error\n", 6);
	exit(1);
}
