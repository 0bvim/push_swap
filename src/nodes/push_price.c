/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_price.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 22:37:36 by vde-frei          #+#    #+#             */
/*   Updated: 2023/12/06 21:17:15 by vde-frei         ###   ########.fr       */
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
		b->push_price = b->pos;
		if (!(b->above_median))
			b->push_price = len_b - (b->pos);
		if (!(b->target_node->above_median))
			b->push_price += b->target_node->pos;
		else
			b->push_price += len_a - (b->target_node->pos);
		b = b->next;
	}
}
