/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:00:51 by nivicius          #+#    #+#             */
/*   Updated: 2023/11/22 11:18:55 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// includes
# include "../lib/libft/includes/libft.h"
// # include "../"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>

// struct and enums
typedef struct s_stack	t_stack;
struct s_stack
{
	int		value;
	t_stack	*next;
	t_stack	*prev;
};

typedef enum e_my_boo
{
	FALSE,
	TRUE,
	ERR,
}		t_my_boo;

// startup functions
int		validation_two(char **argv);
void	stack_init(t_stack **a, char **argv, bool flag);

// handle nodes
void	free_list(t_stack *head);
void	append_node(t_stack **stack, int nbr);
void	error_free(t_stack **a, char **argv, bool flag);
t_stack	*find_last_node(t_stack *head);

#endif
