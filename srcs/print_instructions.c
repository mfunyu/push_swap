#include "push_swap.h"

void	print_instructions(t_list *operation)
{
	while (operation)
	{
		ft_putendl_fd(operation->content, 1);
		operation = operation->next;
	}
}
