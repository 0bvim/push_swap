/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 23:10:08 by vde-frei          #+#    #+#             */
/*   Updated: 2023/12/09 23:11:46 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	exceptions(int r, t_stack *a, t_stack *b);
static void	push_rotate_b(t_stack *a, t_stack *b, t_value *var);
static void	back_to_orig_ra(t_stack *a, t_stack *b, t_value *var);
static void	back_to_orig_rb(t_stack *a, t_stack *b, t_value *var);

void	b_to_a(int r, t_stack *a, t_stack *b, int *count)
{
	int		tmp;
	t_value	var;

	(*count)++;
	if (!exceptions(r, a, b))
		return ;
	init_values(&var);
	select_pivots(r, b, &var);
	tmp = r;
	while (tmp--)
		push_rotate_b(a, b, &var);
	a_to_b(var.pa - var.ra, a, b, count);
	if (var.ra > var.rb)
		back_to_orig_ra(a, b, &var);
	else
		back_to_orig_rb(a, b, &var);
	a_to_b(var.ra, a, b, count);
	b_to_a(var.rb, a, b, count);
}

static int	exceptions(int r, t_stack *a, t_stack *b)
{
	if (r <= 3)
	{
		under_three_handler(r, a, b, B);
		return (0);
	}
	else if (r == 5)
	{
		sort_five_handler(5, a, b, B);
		return (0);
	}
	else
		return (1);
}

static void	push_rotate_b(t_stack *a, t_stack *b, t_value *var)
{
	if (b->top->value <= var->small_pivot)
	{
		rotate_stack(b, B);
		var->rb++;
	}
	else
	{
		push_stack(b, a, A);
		var->pa++;
		if (a->top->value <= var->big_pivot)
		{
			rotate_stack(a, A);
			var->ra++;
		}
	}
}

static void	back_to_orig_ra(t_stack *a, t_stack *b, t_value *var)
{
	int	rrr;
	int	rem;

	rrr = var->rb;
	rem = var->ra - rrr;
	while (rrr--)
		reverse_rotate_both_stack(a, b, ALL);
	while (rem--)
		reverse_rotate_stack(a, A);
}

static void	back_to_orig_rb(t_stack *a, t_stack *b, t_value *var)
{
	int	rrr;
	int	rem;

	rrr = var->ra;
	rem = var->rb - rrr;
	while (rrr--)
		reverse_rotate_both_stack(a, b, ALL);
	while (rem--)
		reverse_rotate_stack(b, B);
}
