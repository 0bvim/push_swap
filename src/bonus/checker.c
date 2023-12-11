/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:25:23 by vde-frei          #+#    #+#             */
/*   Updated: 2023/12/10 23:28:13 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

static void	free_checker(char **argv, t_stack *a);

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	char	*next_line;
	size_t	len;

	a = NULL;
	b = NULL;
	if (argc < 2)
		exit(EXIT_SUCCESS);
	else if (2 == argc)
		argv = ft_split(argv[1], 0x20);
	stack_init(&a, argv + 1, 2 == argc);
	len = stack_len(a);
	next_line = get_next_line(IN);
	while (next_line)
	{
		parse_command(&a, &b, next_line);
		next_line = get_next_line(IN);
	}
	if (stack_sorted(a) && (stack_len(a) == len))
		ft_putstr_fd("OK\n", OUT);
	else
		ft_putstr_fd("KO\n", OUT);
	free_checker(argv, a);
	return (EXIT_SUCCESS);
}

static void	free_checker(char **argv, t_stack *a)
{
	if (argv)
		ft_free_split(argv);
	while (a->prev && (a->prev != a->prev->prev))
		a = a->prev;
	free_list(a);
}
