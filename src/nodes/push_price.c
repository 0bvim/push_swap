/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_price.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivicius <nivicius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 22:37:36 by vde-frei          #+#    #+#             */
/*   Updated: 2023/12/07 01:27:49 by nivicius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_price(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (b)
	{
		b->push_price = b->current_pos;
		if (!(b->above_median))
			b->push_price = len_b - (b->current_pos);
		if (b->target_node->above_median)
			b->push_price += b->target_node->current_pos;
		else
			b->push_price += len_a - (b->target_node->current_pos);
		b = b->next;
	}
}
