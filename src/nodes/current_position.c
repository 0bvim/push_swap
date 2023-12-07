/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   current_position.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 22:52:41 by vde-frei          #+#    #+#             */
/*   Updated: 2023/12/06 21:17:15 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	set_current_position(t_stack *stack)
{
	int	i;
	int	mid_stack;

	i = 0;
	if (NULL == stack)
		return ;
	mid_stack = stack_len(stack) / 2;
	while (stack)
	{
		stack->pos = i;
		if (i <= mid_stack)
			stack->above_median = TRUE;
		else
			stack->above_median = FALSE;
		stack = stack->next;
		++i;
	}
}
