/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_highest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivicius <nivicius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:53:22 by vde-frei          #+#    #+#             */
/*   Updated: 2023/11/30 14:57:37 by nivicius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*find_highest(t_stack *stack)
{
	int		highest;
	t_stack	*highest_node;

	highest_node = NULL;
	if (NULL == stack)
		return (NULL);
	highest = INT_MIN;
	while (stack)
	{
		if (stack->value > highest)
		{
			highest = stack->value;
			highest_node = stack;
		}
		stack = stack->next;
	}
	return (highest_node);
}
