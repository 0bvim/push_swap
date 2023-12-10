/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivicius <nivicius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:14:06 by nivicius          #+#    #+#             */
/*   Updated: 2023/12/10 12:15:35 by nivicius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	rotate_both(t_stack **a, t_stack **b, t_stack *cheap_node);
static void	reverse_rotate_both(t_stack **a, t_stack **b, t_stack *cheap_node);

void	move_nodes(t_stack **a, t_stack **b)
{
	t_stack	*cheap;

	cheap = return_cheapest(*b);
	if (cheap->above_median && cheap->target_node->above_median)
		rotate_both(a, b, cheap);
	else if (!(cheap->above_median) && !(cheap->target_node->above_median))
		reverse_rotate_both(a, b, cheap);
	finish_rotation(b, cheap, 'b');
	finish_rotation(a, cheap->target_node, 'a');
	pa(a, b, false);
}

static void	rotate_both(t_stack **a, t_stack **b, t_stack *cheap_node)
{
	while (*a != cheap_node->target_node && *b != cheap_node)
		rr(a, b, false);
	set_current_position(*a);
	set_current_position(*b);
}

static void	reverse_rotate_both(t_stack **a, t_stack **b, t_stack *cheap_node)
{
	while (*a != cheap_node->target_node && *b != cheap_node)
		rrr(a, b, false);
	set_current_position(*a);
	set_current_position(*b);
}
