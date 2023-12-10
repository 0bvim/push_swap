/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 22:43:27 by vde-frei          #+#    #+#             */
/*   Updated: 2023/12/09 22:49:19 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	exceptions(int r, t_stack *a, t_stack *b);
static void	push_rotate_a(t_stack *a, t_stack *b, t_value *var);
static void	back_to_orig_ra(t_stack *a, t_stack *b, int *count, t_value *var);
static void	back_to_orig_rb(t_stack *a, t_stack *b, int *count, t_value *var);

void	a_to_b(int stack_size, t_stack *a, t_stack *b, int *count)
{
	int		tmp;
	t_value	var;

	if (!exceptions(stack_size, a, b))
		return ;
	init_values(&var);
	select_pivots(stack_size, a, &var);
	tmp = stack_size;
	while (tmp--)
		push_rotate_a(a, b, &var);
	if (var.ra > var.rb)
		back_to_orig_ra(a, b, count, &var);
	else
		back_to_orig_rb(a, b, count, &var);
	a_to_b(var.ra, a, b, count);
	b_to_a(var.rb, a, b, count);
	b_to_a(var.pb - var.rb, a, b, count);
}

static int	exceptions(int r, t_stack *a, t_stack *b)
{
	if (r <= 3)
	{
		under_three_handler(r, a, b, A);
		return (FALSE);
	}
	else if (r == 5)
	{
		sort_five_handler(5, a, b, A);
		return (FALSE);
	}
	else
		return (TRUE);
}

static void	push_rotate_a(t_stack *a, t_stack *b, t_value *var)
{
	if (a->top->value > var->big_pivot)
	{
		rotate_stack(a, A);
		var->ra++;
	}
	else
	{
		push_stack(a, b, B);
		var->pb++;
		if (b->top->value > var->small_pivot)
		{
			rotate_stack(b, B);
			var->rb++;
		}
	}
}

static void	back_to_orig_ra(t_stack *a, t_stack *b, int *count, t_value *var)
{
	int	rrr;
	int	rem;

	rrr = var->rb;
	rem = var->ra - rrr;
	if ((*count) > 0)
	{
		while (rrr--)
			reverse_rotate_both_stack(a, b, ALL);
		while (rem--)
			reverse_rotate_stack(a, A);
	}
	else
	{
		while (rrr--)
			reverse_rotate_stack(b, B);
	}
}

static void	back_to_orig_rb(t_stack *a, t_stack *b, int *count, t_value *var)
{
	int	rrr;
	int	rem;

	rrr = var->ra;
	rem = var->rb - rrr;
	if ((*count) > 0)
	{
		while (rrr--)
			reverse_rotate_both_stack(a, b, ALL);
		while (rem--)
			reverse_rotate_stack(b, B);
	}
	else
	{
		rrr = var->rb;
		while (rrr--)
			reverse_rotate_stack(b, B);
	}
}
