#include "push_swap.h"

void	print_operation(t_op_name name, bool newline)
{
	if (name == sa)
		ft_putstr_fd("sa", 1);
	if (name == sb)
		ft_putstr_fd("sb", 1);
	if (name == ss)
		ft_putstr_fd("ss", 1);
	if (name == pa)
		ft_putstr_fd("pa", 1);
	if (name == pb)
		ft_putstr_fd("pb", 1);
	if (name == ra)
		ft_putstr_fd("ra", 1);
	if (name == rb)
		ft_putstr_fd("rb", 1);
	if (name == rr)
		ft_putstr_fd("rr", 1);
	if (name == rra)
		ft_putstr_fd("rra", 1);
	if (name == rrb)
		ft_putstr_fd("rrb", 1);
	if (name == rrr)
		ft_putstr_fd("rrr", 1);
	if (newline)
		ft_putstr_fd("\n", 1);
}

void	print_instructions(t_info *info)
{
	t_simple	*operation;

	operation = info->instructions;
	while (operation)
	{
		print_operation(operation->value, true);
		operation = operation->next;
	}
}
