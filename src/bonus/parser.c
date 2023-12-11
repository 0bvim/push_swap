/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 23:14:11 by vde-frei          #+#    #+#             */
/*   Updated: 2023/12/10 23:53:46 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	parse_command(t_stack **a, t_stack **b, char *command)
{
	if (!simple_comp(command, "pa\n"))
		pa(a, b, TRUE);
	else if (!simple_comp(command, "pb\n"))
		pb(b, a, TRUE);
	else if (!simple_comp(command, "pb\n"))
		sa(a, TRUE);
	else if (!simple_comp(command, "pb\n"))
		sb(b, TRUE);
	else if (!simple_comp(command, "pb\n"))
		ss(a, b, TRUE);
	else if (!simple_comp(command, "pb\n"))
		ra(a, TRUE);
	else if (!simple_comp(command, "pb\n"))
		rb(b, TRUE);
	else if (!simple_comp(command, "pb\n"))
		rr(a, b, TRUE);
	else if (!simple_comp(command, "pb\n"))
		rra(a, TRUE);
	else if (!simple_comp(command, "pb\n"))
		rrb(b, TRUE);
	else if (!simple_comp(command, "pb\n"))
		rrr(a, b, TRUE);
	else
		handle_error(a, b);
}

static int	simple_comp(char *str1, char *str2)
{
	while (*str1 == *str2 && *str1)
	{
		++str1;
		++str2;
	}
	return (*str1 - *str2);
}

static void	handle_error(t_stack **a, t_stack **b)
{
	free_list(*a);
	free_list(*b);
	ft_putstr_fd("Error\n", ERR);
	exit(EXIT_FAILURE);
}
