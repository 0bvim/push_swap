/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivicius <nivicius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:14:06 by nivicius          #+#    #+#             */
/*   Updated: 2023/12/06 16:58:43 by nivicius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	move_nodes(t_stack **a, t_stack **b)
{
	t_stack	*cheap;

	cheap = return_cheapest(*b);
	if (cheap->above_median && cheap->target_node->above_median)
		rr(a, b, cheap);
	else if (!(cheap->above_median) && !(cheap->target_node->above_median))
		rrr(a, b, cheap);
	finish_rotation(b, cheap, 'b');
	finish_rotation(a, cheap->target_node, 'a');
	pa(a, b, false);
}
