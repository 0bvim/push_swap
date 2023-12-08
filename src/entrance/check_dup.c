/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:21:27 by vde-frei          #+#    #+#             */
/*   Updated: 2023/12/08 16:23:00 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	check_dup(t_node *a)
{
	int		current_value;
	t_node	*tmp;

	while (a->next)
	{
		tmp = a->next;
		current_value = a->value;
		while (tmp)
		{
			if (tmp->value == current_value)
				print_error();
			if (tmp->next)
				tmp = tmp->next;
			else
				break ;
		}
		a = a->next;
	}
	while (a->prev)
		a = a->prev;
}
