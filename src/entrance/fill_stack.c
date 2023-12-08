/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:19:35 by vde-frei          #+#    #+#             */
/*   Updated: 2023/12/08 16:17:52 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_node	*fill_stack(int ac, char **av, t_stack **stack)
{
	int	i;
	int	ret;
	t_node	*node;

	i = 0;
	node = NULL;
	while (++i < ac)
	{
		ret = set_node(av[i], &node, stack);
		if (!ret)
			print_error();
	}
	if (!node->next)
		(*stack)->bottom = node;
	while (node->prev)
		node = node->prev;
	return (node);
}
