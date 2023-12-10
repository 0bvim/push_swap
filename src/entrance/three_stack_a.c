/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_stack_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 21:05:54 by vde-frei          #+#    #+#             */
/*   Updated: 2023/12/09 21:08:50 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	three_top_min_a(t_stack *a, int max);
static void	three_mid_min_a(t_stack *a, int max);
static void	three_bottom_min_a(t_stack *a, int max);

void	three_handler_a(int r, t_stack *a)
{
	int	min;
	int	max;

	min = get_min(a->top, r);
	max = get_max(a->top, r);
	if (a->top->value == min)
		three_top_min_a(a, max);
	else if (a->top->next->value == min)
		three_mid_min_a(a, max);
	else if (a->top->next->next->value == min)
		three_bottom_min_a(a, max);
}

static void	three_top_min_a(t_stack *a, int max)
{
	if (a->size == 3)
	{
		if (a->top->next->value == max)
		{
			reverse_rotate_stack(a, A);
			swap_stack(a, A);
		}
	}
	else
	{
		if (a->top->next->value == max)
		{
			rotate_stack(a, A);
			swap_stack(a, A);
			reverse_rotate_stack(a, A);
		}
	}
}

static void	three_mid_min_a(t_stack *a, int max)
{
	if (a->size == 3)
	{
		if (a->bottom->value == max)
			swap_stack(a, A);
		else
			rotate_stack(a, A);
	}
	else
	{
		swap_stack(a, A);
		if (a->top->next->value == max)
		{
			rotate_stack(a, A);
			swap_stack(a, A);
			reverse_rotate_stack(a, A);
		}
	}
}

static void	three_bottom_min_a(t_stack *a, int max)
{
	if (a->size == 3)
	{
		if (a->top->value == max)
			swap_stack(a, A);
		reverse_rotate_stack(a, A);
	}
	else
	{
		if (a->top->value == max)
			swap_stack(a, A);
		rotate_stack(a, A);
		swap_stack(a, A);
		reverse_rotate_stack(a, A);
		swap_stack(a, A);
	}
}
