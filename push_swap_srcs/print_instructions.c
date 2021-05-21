#include "push_swap.h"

void	print_instructions(t_info *info)
{
	t_list	*operation;

	operation = info->instructions;
	while (operation)
	{
		ft_putendl_fd(operation->content, 1);
		operation = operation->next;
	}
}
