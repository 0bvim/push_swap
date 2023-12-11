/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:25:23 by vde-frei          #+#    #+#             */
/*   Updated: 2023/12/10 21:27:06 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	char	*next_line;
	int		len;

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
	if (stack_sorted(a) && stack_len(a) == len)
		ft_putstr_fd("OK\n", OUT);
	else
		ft_putstr_fd("KO\n", OUT);
	((free(a)) && ft_free_split(argv));
	return (0);
}
