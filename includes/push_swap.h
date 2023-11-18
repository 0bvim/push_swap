/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivicius <nivicius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:00:51 by nivicius          #+#    #+#             */
/*   Updated: 2023/11/18 16:55:08 by nivicius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// includes
# include "../lib/libft/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>
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

// functions
void	free_list(t_stack *head);
t_stack	*find_last_node(t_stack *head);
void	append_node(t_stack **stack, int nbr);
void	stack_init(t_stack **a, char **argv, bool flag);
void	error_free(t_stack **a, char **argv, bool flag);
int		check_double(t_stack *a, int nbr);
int		check_argv(char *argv);

#endif
