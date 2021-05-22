#include "push_swap.h"

void	print_operation(t_operation_name name)
{
	if (name == sa)
		ft_putendl_fd("sa", 1);
	if (name == sb)
		ft_putendl_fd("sb", 1);
	if (name == ss)
		ft_putendl_fd("ss", 1);
	if (name == pa)
		ft_putendl_fd("pa", 1);
	if (name == pb)
		ft_putendl_fd("pb", 1);
	if (name == ra)
		ft_putendl_fd("ra", 1);
	if (name == rb)
		ft_putendl_fd("rb", 1);
	if (name == rr)
		ft_putendl_fd("rr", 1);
	if (name == rra)
		ft_putendl_fd("rra", 1);
	if (name == rrb)
		ft_putendl_fd("rrb", 1);
	if (name == rrr)
		ft_putendl_fd("rrr", 1);
}

void	print_instructions(t_info *info)
{
	t_instruc	*operation;

	operation = info->instructions;
	while (operation)
	{
		print_operation(operation->operation);
		operation = operation->next;
	}
}
