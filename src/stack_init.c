/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivicius <nivicius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 01:21:35 by nivicius          #+#    #+#             */
/*   Updated: 2023/11/15 01:33:01 by nivicius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(t_stack **a, char **argv, bool flag)
{
	long	nbr;

	while (*argv)
	{
		nbr = ft_atol(*argv);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_free(a, argv, flag);
		if (check_double(*a, (int)nbr))
			error_free(a, argv, flag);
		// function to append node params a (int)nbr
		++argv;
	}
}

void	error_free(t_stack **a, char **argv, bool flag)
{
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
