/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_select.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:06:25 by nivicius          #+#    #+#             */
/*   Updated: 2023/12/02 15:33:35 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_select(t_stack *a, t_stack *b)
{
	(void)b;
	if (stack_len(a) == 2)
		sa(&a, FALSE);
	else if (stack_len(a) == 3)
		tiny_sort(&a);
}
