#include "push_swap.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack *b;

	a = NULL;
	b = NULL;
	(void)b;
	if (1 == argc || (2 == argc && !*(*(argv + 1))))
		return (ft_putendl_fd("invalid args\n", 2), 1);
	else if (2 == argc)
		argv = ft_split(argv[1], ' ');
	stack_init(&a, argv + 1, 2 == argc);
	for (int i = 1; i <= argc - 1; i++)
		printf("Pos %d        Value %s\n", i, argv[i]);
	return (EXIT_SUCCESS);
}
