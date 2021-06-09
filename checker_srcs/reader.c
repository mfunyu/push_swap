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

	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(0, &operator);
		if (ret <= 0)
			break ;
		if (!is_valid_operation_type(operator))
		{
			null_free((void **)&operator);
			return (ERROR);
		}
		new = ft_lstnew_dup(operator);
		null_free((void **)&operator);
		if (!new)
			return (FAILURE);
		ft_lstadd_back(instructions, new);
	}
	if (ret < 0)
		return (FAILURE);
	null_free((void **)&operator);
	return (SUCCESS);
}

int	read_instructions(t_list **instructions)
{
	int		ret;

	*instructions = NULL;
	ret = get_each_operation(instructions);
	if (ret != SUCCESS)
		ft_lstclear(instructions, free);
	return (ret);
}
