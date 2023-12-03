/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jackson_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 22:59:43 by vde-frei          #+#    #+#             */
/*   Updated: 2023/12/02 23:26:09 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	jackson_sort(t_stack **a, t_stack **b)
{
		init_node(*a, *b);
		finish_rotation(a, find_smallest(*a), 'a');
		pb(b, a, FALSE);
}
