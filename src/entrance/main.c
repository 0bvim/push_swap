/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:25:38 by vde-frei          #+#    #+#             */
/*   Updated: 2023/12/06 23:33:49 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	int		stack_size;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (EXIT_FAILURE);
	if (!validation_two(argv))
		free_all(a, b);
	stack_init(&a, argv + 1, 2 == argc);
	stack_size = stack_len(a);
	// set_index(a, stack_size + 1);
	if (!stack_sorted(a))
		sort_select(a, b);
	free_all(a, b);
}
