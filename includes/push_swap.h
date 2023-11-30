/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivicius <nivicius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:00:51 by nivicius          #+#    #+#             */
/*   Updated: 2023/11/30 14:43:46 by nivicius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// includes
# include "../lib/libft/includes/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>

// struct and enums
typedef struct s_stack	t_stack;
struct s_stack
{
	int		value;
	int		split;
	t_stack	*next;
	t_stack	*prev;
};

typedef enum e_my_boo
{
	FALSE,
	TRUE,
	ERR,
	OUT = 0,
}		t_my_boo;

/* startup functions */
int		validation_two(char **argv);
void	stack_init(t_stack **a, char **argv, bool flag);

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
bool	stack_sorted(t_stack *stack);
void	tiny_sort(t_stack **a);

#endif
