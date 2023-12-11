/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 03:43:01 by vde-frei          #+#    #+#             */
/*   Updated: 2023/12/11 14:19:53 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	swap(t_stack **head)
{
	if (NULL == *head || NULL == head || (stack_len(*head) < 2))
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	sa(t_stack **a, bool checker)
{
	swap(a);
	if (!checker)
		write(OUT, "sa\n", 3);
}

void	sb(t_stack **b, bool checker)
{
	swap(b);
	if (!checker)
		write(OUT, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, bool checker)
{
	swap(a);
	swap(b);
	if (!checker)
		write(OUT, "ss\n", 3);
}
