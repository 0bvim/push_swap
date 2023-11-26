/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 03:43:18 by vde-frei          #+#    #+#             */
/*   Updated: 2023/11/26 13:33:34 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	rotate(t_stack **head)
{
	t_stack	*last_node;

	if (NULL == *head || NULL == head)
		return ;
	last_node = find_last_node(*head);
	last_node->next = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_stack **a, bool checker)
{
	rotate(a);
	if (!checker)
		write(OUT, "ra\n", 3);
}

void	rb(t_stack **b, bool checker)
{
	rotate(b);
	if (!checker)
		write(OUT, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, bool checker)
{
	rotate(a);
	rotate(b);
	if (!checker)
		write(OUT, "rr\n", 3);
}
