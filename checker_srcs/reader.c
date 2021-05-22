#include "checker.h"

bool	is_valid_operation_type(char *operation)
{
	if (ft_strncmp(operation, "sa", 3) == 0)
		return (true);
	if (ft_strncmp(operation, "sb", 3) == 0)
		return (true);
	if (ft_strncmp(operation, "ss", 3) == 0)
		return (true);
	if (ft_strncmp(operation, "pa", 3) == 0)
		return (true);
	if (ft_strncmp(operation, "pb", 3) == 0)
		return (true);
	if (ft_strncmp(operation, "ra", 3) == 0)
		return (true);
	if (ft_strncmp(operation, "rb", 3) == 0)
		return (true);
	if (ft_strncmp(operation, "rr", 3) == 0)
		return (true);
	if (ft_strncmp(operation, "rra", 4) == 0)
		return (true);
	if (ft_strncmp(operation, "rrb", 4) == 0)
		return (true);
	if (ft_strncmp(operation, "rrr", 4) == 0)
		return (true);
	return (false);
}

static int	get_each_operation( t_list **instructions)
{
	t_list	*new;
	char	*operator;
	int		ret;

	while (1)
	{
		ret = get_next_line(0, &operator);
		if (ret < 0)
			exit(EXIT_FAILURE);
		if (ret == 0)
			return (SUCCESS);
		if (!is_valid_operation_type(operator))
		{
			null_free((void **)&operator);
			return (ERROR);
		}
		new = ft_lstnew_dup(operator);
		if (!new)
			exit(EXIT_FAILURE);
		if (ft_lstadd_back(instructions, new) == ERROR)
			exit(EXIT_FAILURE);
		null_free((void **)&operator);
	}
	return (SUCCESS);
}

int	read_instructions(t_stack **stack_a, t_list **instructions)
{
	*instructions = NULL;
	if (get_each_operation(instructions) == ERROR)
	{
		stacklst_clear(stack_a);
		ft_lstclear(instructions, free);
		ft_putendl_fd("Error", 2);
		return (ERROR);
	}
	return (SUCCESS);
}
