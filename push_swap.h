/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:02:43 by lkramer           #+#    #+#             */
/*   Updated: 2025/02/11 11:43:06 by lkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h> 
# include <limits.h>
# include "libft/libft.h"

typedef struct s_stack_node
{
	int						nbr;
	int						index;
	struct s_stack_node		*next;
}	t_stack_node;

/* Error handling  */
int				error_syntax(char *str_num);
int				error_dup(t_stack_node *a, int n);
void			free_stack(t_stack_node **stack);
void			free_errors(t_stack_node **a, char **argv, int is_split);
void			free_array(char **argv);

/* Stack initiation   */
long			ft_atol(const char *s);
t_stack_node	*create_node(int nbr);
void			append_node(t_stack_node **a, int nbr);
void			init_stack_a(t_stack_node **a, char **argv, int is_split);

/* Utils */
bool			stack_sorted(t_stack_node *a);
int				stack_size(t_stack_node *stack);
t_stack_node	*find_min_node(t_stack_node *stack);
int				is_only_spaces(char *argv);
int				handle_input(int argc, char ***argv, int *is_split);

/* Commands */
void			swap_a(t_stack_node **a);
void			rotate_a(t_stack_node **a);
void			reverse_rotate_a(t_stack_node **a);
void			push_a(t_stack_node **a, t_stack_node **b);
void			push_b(t_stack_node **a, t_stack_node **b);

/* algorithm  */
void			check_stack_size(t_stack_node **a, t_stack_node **b);
void			sort_three(t_stack_node **a);
void			sort_four_five(t_stack_node **a, t_stack_node **b);
void			radix_sort(t_stack_node **a, t_stack_node **b);

/* indices  */
void			assign_indices(t_stack_node *stack);
int				get_max_bits(t_stack_node *stack);
t_stack_node	*find_min_unindexed(t_stack_node *stack);

#endif