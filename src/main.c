/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:25:38 by vde-frei          #+#    #+#             */
/*   Updated: 2023/11/21 10:04:53 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	validate_entrance(char **argv);

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	(void)b;
	if (argc < 2)
		return (EXIT_FAILURE);
	else if (2 == argc)
	{
		if (validate_entrance(argv))
			return (ft_putstr_fd("Error\n", 2), EXIT_FAILURE);
		else if (!argv[1][0] || ft_isdigit(argv[1][0]))
			return (EXIT_FAILURE);
		//verify why when I use the second arg with quotes, programm not
		//return the message saying "error" in terminal.
		argv = ft_split(argv[1], ' ');
	}
	stack_init(&a, argv + 1, 2 == argc);
	free_list(a);
	return (EXIT_SUCCESS);
}

static int	validate_entrance(char **argv)
{
	if (argv[1][0] == '\0')
		return (TRUE);
	else if (ft_isascii(argv[1][0]) && (!ft_isdigit(argv[1][0])))
		return (TRUE);
	else
		return (FALSE);
}
