/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:25:38 by vde-frei          #+#    #+#             */
/*   Updated: 2023/11/26 13:34:31 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	int		split;

	a = NULL;
	b = NULL;
	split = 0;
	(void)b;
	if (argc < 2)
		return (EXIT_FAILURE);
	else if (2 == argc)
	{
		validation_two(argv);
		argv = ft_split(argv[1], ' ');
		split = TRUE;
		stack_init(&a, argv, 2 == argc);
	}
	else
		stack_init(&a, argv + 1, 2 == argc);
	if (split == TRUE)
		ft_free_split(argv);
	free_list(a);
	return (EXIT_SUCCESS);
}
