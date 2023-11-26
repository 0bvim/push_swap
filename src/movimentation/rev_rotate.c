/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 03:43:30 by vde-frei          #+#    #+#             */
/*   Updated: 2023/11/26 16:15:01 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	rev_rotate(t_stack **head)
{
	t_stack	*last_node;

	if (NULL == *head || NULL == head)
		return ;
	last_node = find_last_node(*head);
	last_node->prev->next = NULL;
	last_node->next = *head;
	last_node->prev = NULL;
	*head = last_node;
	last_node->next->prev = last_node;
}

void	rra(t_stack **a, bool checker)
{
	rev_rotate(a);
	if (!checker)
		write(OUT, "rra\n", 4);
}

void	rrb(t_stack **b, bool checker)
{
	rev_rotate(b);
	if (!checker)
		write(OUT, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, bool checker)
{
	rev_rotate(a);
	rev_rotate(b);
	if (!checker)
		write(OUT, "rrr\n", 4);
}
