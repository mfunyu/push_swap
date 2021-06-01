#include "push_swap.h"

void	print_operation(t_op_name name, bool newline)
{
	if (name == sa)
		ft_putstr_fd("sa", STDOUT_FILENO);
	if (name == sb)
		ft_putstr_fd("sb", STDOUT_FILENO);
	if (name == ss)
		ft_putstr_fd("ss", STDOUT_FILENO);
	if (name == pa)
		ft_putstr_fd("pa", STDOUT_FILENO);
	if (name == pb)
		ft_putstr_fd("pb", STDOUT_FILENO);
	if (name == ra)
		ft_putstr_fd("ra", STDOUT_FILENO);
	if (name == rb)
		ft_putstr_fd("rb", STDOUT_FILENO);
	if (name == rr)
		ft_putstr_fd("rr", STDOUT_FILENO);
	if (name == rra)
		ft_putstr_fd("rra", STDOUT_FILENO);
	if (name == rrb)
		ft_putstr_fd("rrb", STDOUT_FILENO);
	if (name == rrr)
		ft_putstr_fd("rrr", STDOUT_FILENO);
	if (newline)
		ft_putstr_fd("\n", STDOUT_FILENO);
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
