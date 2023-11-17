/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:25:38 by vde-frei          #+#    #+#             */
/*   Updated: 2023/11/16 20:50:32 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	(void)b;
	if (1 == argc || (2 == argc && !*(*(argv + 1))))
		return (ft_putendl_fd("invalid args\n", 2), 1);
	else if (2 == argc)
		argv = ft_split(argv[1], ' ');
	stack_init(&a, argv + 1, 2 == argc);
	// free_list(a);
	return (EXIT_SUCCESS);
}
