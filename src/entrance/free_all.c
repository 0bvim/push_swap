/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:08:57 by nivicius          #+#    #+#             */
/*   Updated: 2023/12/10 23:36:36 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	free_all(int split, char **argv, t_stack *a, t_stack *b)
{
	if (split == TRUE)
		ft_free_split(argv);
	while (a->prev && (a->prev != a->prev->prev))
		a = a->prev;
	free_list(a);
	if (b)
	{
		while (b->prev)
			b = b->prev;
		free_list(b);
	}
	return (EXIT_SUCCESS);
}
