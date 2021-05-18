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

int	read_instructions(t_stack **stack_a, t_list **instructions)
{
	char	*operator;
	int		error;
	int		ret;

	ret = 1;
	error = 0;
	*instructions = NULL;
	while (!error && ret)
	{
		ret = get_next_line(0, &operator);
		if (ret && !is_valid_operation_type(operator))
			error = 1;
		if (!error && ret && ft_lstadd_back(instructions,
				ft_lstnew(ft_strdup(operator))) == ERROR)
			exit(EXIT_FAILURE);
		null_free(&operator);
	}
	if (ret < 0)
		exit(EXIT_FAILURE);
	if (error || !(*instructions))
	{
		stacklst_clear(stack_a);
		ft_lstclear(instructions, free);
		ft_putendl_fd("Error", 2);
		return (ERROR);
	}
	return (SUCCESS);
}
