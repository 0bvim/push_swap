/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 02:26:11 by vde-frei          #+#    #+#             */
/*   Updated: 2023/11/22 11:49:02 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	validate_entrance(char **argv);

void	error_free(t_stack **a, char **argv, bool flag)
{
	(void)argv;
	(void)flag;
	ft_putstr_fd("Error\n", 2);
	if (!*a)
		exit(ERR);
	free_list(*a);
	exit(ERR);
}

int	validation_two(char **argv)
{
	if (validate_entrance(argv))
	{
		ft_putstr_fd("Error\n", 2);
		exit (EXIT_FAILURE);
	}
	else if (ft_isdigit(argv[1][0]) && !(ft_isascii(argv[1][0])))
		return (EXIT_FAILURE);
	return (TRUE);
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
