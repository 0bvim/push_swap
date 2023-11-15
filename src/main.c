#include "push_swap.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
	// t_stack	*a;
	// t_stack *b;

	// a = NULL;
	// b = NULL;
	if (1 == argc || (2 == argc && !*(*(argv + 1))))
		return (ft_putendl_fd("invalid args\n", 2), 1);
	else if (2 == argc)
		argv = ft_split(argv[1], ' ');
	for (int i = 1; i < argc; i++)
		printf("Pos %d        Value %s\n", i, argv[i]);
	return (ft_putendl_fd("valid args\n", 1), 0);
}
