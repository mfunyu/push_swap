#include "push_swap.h"

static t_operation_type	set_operation_type2(t_operation_name type,
								t_operation_name prev, char **operation)
{
	if (type == rra || type == rrb)
	{
		if (type == rra && prev != rrb)
			*operation = "rra";
		else if (type == rrb && prev != rra)
			*operation = "rrb";
		else
			*operation = "rrr";
		return (revrotate);
	}
	else
	{
		if (type == pa)
			*operation = "pa";
		else if (type == pb)
			*operation = "pb";
		return (push);
	}
	return (0);
}

static t_operation_type	set_operation_type1(t_operation_name type,
								t_operation_name prev, char **operation)
{
	if (type == sa || type == sb)
	{
		if (type == sa && prev != sb)
			*operation = "sa";
		else if (type == sb && prev != sa)
			*operation = "sb";
		else
			*operation = "ss";
		return (swap);
	}
	else if (type == ra || type == rb)
	{
		if (type == ra && prev != rb)
			*operation = "ra";
		else if (type == rb && prev != ra)
			*operation = "rb";
		else
			*operation = "rr";
		return (rotate);
	}
	return (set_operation_type2(type, prev, operation));
}

void	exec_add_instructions(t_stack **stacksrc, t_stack **stackdst,
							t_list **instructions, t_operation_name op_name)
{
	static t_operation_name	prev;
	t_operation_type		op_type;
	char					*operation;

	op_type = set_operation_type1(op_name, prev, &operation);
	prev = op_name;
	if (op_type == swap)
		operation_swap_one(stacksrc);
	else if (op_type == push)
		operation_push_one(stacksrc, stackdst);
	else if (op_type == rotate)
		operation_rotate_one(stacksrc);
	else if (op_type == revrotate)
		operation_revrotate_one(stacksrc);
	if (ft_lstadd_back(instructions, ft_lstnew_dup(operation)) == ERROR)
		exit(EXIT_FAILURE);
}
