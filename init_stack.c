/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:48:47 by lkramer           #+#    #+#             */
/*   Updated: 2025/02/05 21:52:48 by lkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 
Takes a string and returns an integer 
(considers long integer for larger numbers)
 */
long	ft_atol(const char *s)
{
	int	sign;
	long result;

	sign = 1;
	result = 0;
	while (*s == 32 || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
	{
		result = result * 10 + (*s - '0');
		s++;
	}
	return (sign * result);
}

/* 
Takes a integer and allocates a memory for a node.
Also initializes leftover struct field, to ensure no garbage values
are contained and prevent undefined behaviour
 */
t_stack_node	*create_node(int nbr) 
{
    t_stack_node	*new_node;
	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		return (NULL);

	new_node->nbr = nbr;
    new_node->next = NULL;
    return (new_node);
}

/* 
Takes nbr, *a, and appends each nbr to newly created
nodes in double linked list *a
 */
void	append_node(t_stack_node **a, int nbr)
{
	t_stack_node	*new_node;
	t_stack_node	*current;

	new_node = create_node(nbr);
	if (!new_node)
		return;
	if (!*a)
    {
        *a = new_node;
        return;
    }
	current = *a;
	while (current->next)
		current = current->next;

	current->next = new_node;  
}
/* 
Takes *a and command line argument.
Returns initiated stack with double linked list
 */
void	init_stack_a(t_stack_node **a, char **argv, int is_split)
{
	long	num;
	int 	i;

	if (is_split)
		i = 0;
	else
		i = 1;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			free_errors(a);
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			free_errors(a);
		if (error_dup(*a, (int)num))
			free_errors(a);
		append_node(a, (int)num);
		i++;
	}
}
