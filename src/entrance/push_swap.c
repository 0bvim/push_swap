/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:47:43 by vde-frei          #+#    #+#             */
/*   Updated: 2023/12/09 15:17:01 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	init_values(t_value *var)
{
	var->ra = 0;
	var->rb = 0;
	var->pa = 0;
	var->pb = 0;
}

void	select_pivots(int	stack_size, t_stack *stack, t_value *var)
{
	long	min;
	long	max;

	min = get_min(stack->top, stack_size);
	max = get_max(stack->top, stack_size);
	var->big_pivot = (min + max) / 2;
	var->small_pivot = (min + var->big_pivot) / 2;
}

void	push_swap(t_stack *a, t_stack *b)
{
	int	count;

	count = 0;
	if (a->size == 5)
		five_handler(a, b);
	else
		pa_to_pb(a->size, a, b, &count);
}
