/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivicius <nivicius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:45:51 by nivicius          #+#    #+#             */
/*   Updated: 2023/11/30 13:48:08 by nivicius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

size_t	stack_len(t_stack *node)
{
	size_t	size;

	size = 0;
	while (node)
	{
		size++;
		node = node->next;
	}
	return (size);
}
