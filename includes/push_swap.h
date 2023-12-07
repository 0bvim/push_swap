/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:00:51 by nivicius          #+#    #+#             */
/*   Updated: 2023/12/06 23:17:19 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// includes
# include "../lib/libft/includes/libft.h"
# include <limits.h>
# include <stdbool.h>

// struct and enums
typedef struct s_stack	t_stack;
struct s_stack
{
	int		value;
	int		index;
	int		pos;
	int		target_pos;
	int		cost_a;
	int		cost_b;
	int		push_price;
	bool	above_median;
	bool	cheapest;
	t_stack	*target_node;
	t_stack	*next;
	t_stack	*prev;
};

typedef enum e_my_boo
{
	FALSE,
	TRUE,
	ERR,
	OUT = 1,
}		t_my_boo;

/* startup functions */
int		validation_two(char **argv);
int		free_all(t_stack *a, t_stack *b);
void	stack_init(t_stack **a, char **argv, bool flag);
void	sort_select(t_stack *a, t_stack *b);
void	set_index(t_stack *stack, size_t size);

/* handle nodes */
void	free_list(t_stack *head);
void	append_node(t_stack **stack, int nbr);
void	error_free(t_stack **a, char **argv, bool flag);
size_t	stack_len(t_stack *node);
t_stack	*find_last_node(t_stack *head);

/* swap moviments */
void	sa(t_stack **a, bool checker);
void	sb(t_stack **b, bool checker);
void	ss(t_stack **a, t_stack **b, bool checker);

/* rotate moviments */
void	ra(t_stack **a, bool checker);
void	rb(t_stack **b, bool checker);
void	rr(t_stack **a, t_stack **b, bool checker);

/* rev_rotate moviments */
void	rra(t_stack **a, bool checker);
void	rrb(t_stack **b, bool checker);
void	rrr(t_stack **a, t_stack **b, bool checker);

/* push moviments */
void	pa(t_stack **a, t_stack **b, bool checker);
void	pb(t_stack **a, t_stack **b, bool checker);

/* sorting */
t_stack	*find_highest(t_stack *stack);
t_stack	*find_smallest(t_stack *stack);
t_stack	*return_cheapest(t_stack *stack);
bool	stack_sorted(t_stack *stack);
void	tiny_sort(t_stack **a);
void	push_swap(t_stack **a, t_stack **b);
void	set_target_node(t_stack *a, t_stack *b);
void	push_price(t_stack *a, t_stack *b);
void	set_current_position(t_stack *stack);
void	jackson_sort(t_stack **a, t_stack **b);
void	init_node(t_stack *a, t_stack *b);
void	set_cheapest(t_stack *b);
void	finish_rotation(t_stack **stack, t_stack *top_node, char stack_name);
void	move_nodes(t_stack **a, t_stack **b);

#endif
