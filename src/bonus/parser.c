/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 23:14:11 by vde-frei          #+#    #+#             */
/*   Updated: 2023/12/11 06:24:56 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

static int	simple_comp(char *str1, char *str2);
static void	handle_error(t_stack **a, t_stack **b);

void	parse_command(t_stack **a, t_stack **b, char *command)
{
	if (!simple_comp(command, "pa\n"))
		pa(a, b, TRUE);
	else if (!simple_comp(command, "pb\n"))
		pb(b, a, TRUE);
	else if (!simple_comp(command, "sa\n"))
		sa(a, TRUE);
	else if (!simple_comp(command, "sb\n"))
		sb(b, TRUE);
	else if (!simple_comp(command, "ss\n"))
		ss(a, b, TRUE);
	else if (!simple_comp(command, "ra\n"))
		ra(a, TRUE);
	else if (!simple_comp(command, "rb\n"))
		rb(b, TRUE);
	else if (!simple_comp(command, "rr\n"))
		rr(a, b, TRUE);
	else if (!simple_comp(command, "rra\n"))
		rra(a, TRUE);
	else if (!simple_comp(command, "rrb\n"))
		rrb(b, TRUE);
	else if (!simple_comp(command, "rrr\n"))
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
	return ((unsigned char)*str1 - (unsigned char)*str2);
}

static void	handle_error(t_stack **a, t_stack **b)
{
	free_list(*a);
	free_list(*b);
	ft_putstr_fd("Error\n", ERR);
	exit(EXIT_FAILURE);
}
