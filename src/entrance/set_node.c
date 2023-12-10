/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:27:52 by vde-frei          #+#    #+#             */
/*   Updated: 2023/12/09 23:20:13 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	set_node(char *argv, t_node **node, t_stack **stack)
{
	int		i;
	char	**args;
	t_node	*tmp;

	args = ft_split(argv, ' ');
	if (!*args || !args)
	{
		ft_free_split(args);
		return (EXIT_FAILURE);
	}
	i = -1;
	while (args[++i])
	{
		tmp = init_node();
		if (!tmp)
		{
			ft_free_split(args);
			print_error();
		}
		tmp->value = atol(args[i]);
		connect_nodes(&tmp, node, stack);
		(*stack)->size++; // maybe need to free each time
	}
	ft_free_split(args);
	return (FALSE);
}
