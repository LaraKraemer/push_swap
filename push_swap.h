/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:02:43 by lkramer           #+#    #+#             */
/*   Updated: 2025/01/31 16:12:20 by lkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// printing command 
# include <stdbool.h> 
// min and max
# include <limits.h>
# include "libft/libft.h"
// add print
# include "printf/ft_printf.h"

typedef struct	s_stack_node
{
	int 				nbr;
	int					index;
	int 				push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
}  	t_stack_node; 

/* Error handling  */
int				error_syntax(char *str_num); 
int				error_dup(t_stack_node *a, int n);
void			free_stack(t_stack_node **stack);
void			free_errors(t_stack_node **a);


/* Stack initiation   */
static long		ft_atol(const char *s);
t_stack_node	*create_node(int nbr);
void			append_node(t_stack_node **a, int nbr);
void			init_stack_a(t_stack_node **a, char **argv);

/* Utils */
bool			stack_sorted(t_stack_node *a);
int				stack_size(t_stack_node *stack);
t_stack_node	*find_min_node(t_stack_node *stack);
t_stack_node	*find_max_node(t_stack_node *stack);
t_stack_node	*find_last_node(t_stack_node *stack);

/* Commands */
void			swap_a(t_stack_node **a);
void			swap_b(t_stack_node **b);
void			swap_ss(t_stack_node **a, t_stack_node **b);
void			rotate_a(t_stack_node **a);
void			rotate_b(t_stack_node **b);
void			rotate_rr(t_stack_node **a, t_stack_node **b);
void			reverse_rotate_a(t_stack_node **a);
void			reverse_rotate_b(t_stack_node **b);
void			reverse_rotate_rr(t_stack_node **a, t_stack_node **b);

/* algorithm  */
void			sort_two(t_stack_node **a);
void			sort_three(t_stack_node **a);
void			print_stack(t_stack_node *stack);

// init_node_a_to_b.c
void			cur_index(t_stack_node *stack);
static void		find_target_a(t_stack_node *a, t_stack_node *b);
void			push_cost(t_stack_node *a, t_stack_node *b);
void			find_cheapest(t_stack_node *stack);
void			init_nodes_a(t_stack_node *a, t_stack_node *b);


// init_node_b_to_a
void			init_nodes_b(t_stack_node *a, t_stack_node *b);
static void	find_target_b(t_stack_node *a, t_stack_node *b);


// push_command.c
static void		push_command(t_stack_node **dest_stack, t_stack_node **src_stack);
void			push_a(t_stack_node **a, t_stack_node **b);
void			push_b(t_stack_node **a, t_stack_node **b);

// cost_analysis.c
void			move_node_to_top(t_stack_node **stack, t_stack_node *top_node, char stack_name);
t_stack_node	*return_best_node(t_stack_node *stack);


// sorting_turk.c 
void			sorting_turk(t_stack_node **a, t_stack_node **b);
static void		rev_rotate_both(t_stack_node **a,
								t_stack_node **b,
								t_stack_node *cheapest_node);
static void		rotate_both(t_stack_node **a,
						t_stack_node **b,
						t_stack_node *cheapest_node);
static void	move_a_to_b(t_stack_node **a, t_stack_node **b);
static void	move_b_to_a(t_stack_node **a, t_stack_node **b);
static void	check_min_on_top(t_stack_node **a);


#endif