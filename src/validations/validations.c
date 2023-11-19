/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 02:26:11 by vde-frei          #+#    #+#             */
/*   Updated: 2023/11/19 03:37:29 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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
