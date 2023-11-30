/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivicius <nivicius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:25:38 by vde-frei          #+#    #+#             */
/*   Updated: 2023/11/30 14:56:39 by nivicius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	free_all(int split, char **argv, t_stack *a, t_stack *b);
static void	sort_select(t_stack *a, t_stack *b);

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (EXIT_FAILURE);
	else if (2 == argc)
	{
		validation_two(argv);
		argv = ft_split(argv[1], ' ');
		a->split = TRUE;
		stack_init(&a, argv, 2 == argc);
	}
	else
		stack_init(&a, argv + 1, 2 == argc);
	if (!stack_sorted(a))
		sort_select(a, b);
	free_all(a->split, argv, a, b);
}

static void	sort_select(t_stack *a, t_stack *b)
{
	(void)b;
	if (stack_len(a) == 2)
		sa(&a, false);
	else if (stack_len(a) == 3)
		tiny_sort(&a);
}

static int	free_all(int split, char **argv, t_stack *a, t_stack *b)
{
	if (split == TRUE)
		ft_free_split(argv);
	free_list(a);
	if (b)
		free_list(b);
	return (EXIT_SUCCESS);
}
