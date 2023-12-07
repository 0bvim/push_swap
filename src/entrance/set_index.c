/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 23:12:47 by vde-frei          #+#    #+#             */
/*   Updated: 2023/12/06 23:33:11 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	set_index(t_stack *stack, size_t size)
{
	t_stack	*aux;
	t_stack *highest;
	int		value;

	while (--size > 0)
	{
		aux = stack;
		value = INT_MIN;
		highest = NULL;
		while (aux)		
		{
			if (aux->value == INT_MIN && aux->index == 0)
				aux->index = 1;
			if (aux->value > value && aux->index == 0)
			{
				value = aux->value;
				highest = aux;
				aux = stack;
			}
			else
				aux = aux->next;
		}
		if (highest != NULL)
			highest->index = size;
	}
}
