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
	t_stack	*highest_node;
	t_stack *last_node;

	highest_node = NULL;
	last_node = NULL;
	highest_node = find_highest(*a);
	last_node = find_last_node(*b);
}
