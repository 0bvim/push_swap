/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:25:38 by vde-frei          #+#    #+#             */
/*   Updated: 2023/11/18 04:54:28 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (EXIT_FAILURE);
	else if (2 == argc)
	{
		if (!argv[1][0] || (!ft_isdigit(argv[1][0])))
			return (ft_putstr_fd("Error\n", 2), EXIT_FAILURE);
		argv = ft_split(argv[1], ' ');
	}
	stack_init(&a, argv + 1, 2 == argc);
	free_list(a);
	return (EXIT_SUCCESS);
}
