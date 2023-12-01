/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivicius <nivicius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:08:57 by nivicius          #+#    #+#             */
/*   Updated: 2023/12/01 11:09:40 by nivicius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	free_all(int split, char **argv, t_stack *a, t_stack *b)
{
	if (split == TRUE)
		ft_free_split(argv);
	free_list(a);
	if (b)
		free_list(b);
	return (EXIT_SUCCESS);
}
