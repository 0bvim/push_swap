/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivicius <nivicius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 01:52:31 by nivicius          #+#    #+#             */
/*   Updated: 2023/12/09 01:53:31 by nivicius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_sorted(t_stack *a)
{
	t_node	*node;

	node = a->top;
	while (node)
	{
		if (node->next)
		{
			if (node->value > node->next->value)
				return (FALSE);
		}
		if (node->next)
			node = node->next;
		else
			break ;
	}
	if (node->value == a->bottom->value)
		return (TRUE);
	else
		return (FALSE);
}
