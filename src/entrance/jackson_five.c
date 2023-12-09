/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jackson_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:23:00 by vde-frei          #+#    #+#             */
/*   Updated: 2023/12/09 20:50:29 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	five_handler(t_stack *a, t_stack *b)
{
	int	pb;
	int	mid;

	pb = 0;
	mid = get_mid_five(a->top);
	while (TRUE)
	{
		if (a->top->value < mid)
		{
			push_stack(a, b, B);
			pb++;
		}
		else
			rotate_stack(a, A);
		if (pb == 2)
			break ;
	}
	three_handler_a(3, a);
	two_handler(a, b, B);
}
