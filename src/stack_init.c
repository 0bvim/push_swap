/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivicius <nivicius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:22:52 by vde-frei          #+#    #+#             */
/*   Updated: 2023/11/18 16:55:17 by nivicius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	error_free(t_stack **a, char **argv, bool flag)
{
	(void)argv;
	(void)flag;
	ft_putstr_fd("Error\n", 2);
	free_list(*a);
	exit(ERR);
}

int	check_double(t_stack *a, int nbr)
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

int	check_argv(char *argv)
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
