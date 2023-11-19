/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:22:52 by vde-frei          #+#    #+#             */
/*   Updated: 2023/11/19 03:22:45 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_argv(char *argv);
static int	check_double(t_stack *a, int nbr);

void	stack_init(t_stack **a, char **argv, bool flag)
{
	long	nbr;

	while (*argv)
	{
		if (check_argv(*argv))
			error_free(a, argv, flag);
		nbr = ft_atol(*argv);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_free(a, argv, flag);
		if (check_double(*a, (int)nbr))
			error_free(a, argv, flag);
		append_node(a, (int)nbr);
		++argv;
	}
}

static int	check_double(t_stack *a, int nbr)
{
	if (NULL == a)
		return (FALSE);
	while (a)
	{
		if (a->value == nbr)
			return (TRUE);
		a = a->next;
	}
	return (FALSE);
}

static int	check_argv(char *argv)
{
	if (!*argv)
		return (TRUE);
	if (*argv == '-' || *argv == '+')
		argv++;
	while (*argv)
		if (!ft_isdigit(*argv++))
			return (TRUE);
	return (FALSE);
}
