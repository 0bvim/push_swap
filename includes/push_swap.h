/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:00:51 by nivicius          #+#    #+#             */
/*   Updated: 2023/12/09 21:12:54 by vde-frei         ###   ########.fr       */
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
typedef struct s_value	t_value;
typedef struct s_node	t_node;

struct	s_node
{
	int		value;
	t_node	*prev;
	t_node	*next;
};

typedef struct s_stack
{
	int		size;
	t_node	*top;
	t_node	*bottom;
};

struct s_value
{
	long	big_pivot;
	long	small_pivot;
	int		ra;
	int		rb;
	int		pa;
	int		pb;
};

typedef enum e_my_boo
{
	FALSE,
	TRUE,
	ERR,
	OUT = 1,
	A = 1,
	B,
	ALL,
}		t_my_boo;

/* startup functions */
t_stack	*init_stack(void);
t_node	*fill_stack(int ac, char **av, t_stack **stack);
void	check_dup(t_node *a);
void	connect_nodes(t_node **tmp, t_node **node, t_stack **stack);
int		set_node(char *argv, t_node **node, t_stack **stack);
int		is_sorted(t_stack *a);
int		get_min(t_node *node, int size);
int		get_max(t_node *node, int size);
int		get_mid_five(t_node *node);
void	init_values(t_value *var);
void	select_pivots(int	stack_size, t_stack *stack, t_value *var);
void	push_swap(t_stack *a, t_stack *b);
void	five_handler(t_stack *a, t_stack *b);
void	push_stack(t_stack *from, t_stack *to, int flag);
void	rotate_stack(t_stack *stack, int flag);
void	rotate_both_stack(t_stack *a, t_stack *b, int flag);
void	reverse_rotate_stack(t_stack *stack, int flag);
void	reverse_rotate_both_stack(t_stack *a, t_stack *b, int flag);
void	three_handler_a(int r, t_stack *a);
void	three_handler_b(int r, t_stack *a, t_stack *b);
void	three_top_min_b(t_stack *b, int max);
void	three_mid_min_b(t_stack *b, int max);
void	three_bottom_min_b(t_stack *b, int max);


/* handle errors */
int		free_all(t_stack *a, t_stack *b);
void	print_error();

/* handle nodes */
void	free_list(t_stack *head);
void	append_node(t_stack **stack, int nbr);
void	error_free(t_stack **a, char **argv);
size_t	stack_len(t_stack *node);
t_stack	*find_last_node(t_stack *head);

/* swap moviments */
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

/* rotate moviments */
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

/* rev_rotate moviments */
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

/* push moviments */
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

/* sorting */
t_stack	*find_highest(t_stack *stack);
t_stack	*find_smallest(t_stack *stack);

#endif
