/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_select.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivicius <nivicius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:06:25 by nivicius          #+#    #+#             */
/*   Updated: 2023/12/01 11:10:21 by nivicius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_select(t_stack *a, t_stack *b)
{
	(void)b;
	if (stack_len(a) == 2)
		sa(&a, false);
	else if (stack_len(a) == 3)
		tiny_sort(&a);
}
