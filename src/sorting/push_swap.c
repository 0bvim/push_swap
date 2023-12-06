/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:50:18 by vde-frei          #+#    #+#             */
/*   Updated: 2023/12/02 20:32:21 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_swap(t_stack **a, t_stack **b)
{
	t_stack		*smallest;
	int			len_a;

	len_a = stack_len(*a);
	if (len_a == 5)
		jackson_sort(a, b);
	else
	{
		while (len_a-- > 3)
			pb(b, a, FALSE);
	}
	tiny_sort(a);
	while (*b)
	{
		init_node(*a, *b);
		move_nodes(a, b);
	}
	set_current_position(*a);
	smallest = find_smallest(*a);
	if (smallest->above_median)
		while (*a != smallest)
			ra(a, false);
	else
		while (*a != smallest)
			rra(a, false);
}
