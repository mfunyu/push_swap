#include "push_swap.h"

static void	add_operation(t_list **instructions, char *operation)
{
	if (ft_lstadd_back(instructions, ft_lstnew_dup(operation)) == ERROR)
		exit(EXIT_FAILURE);
}

// static void	rmv_operation(t_list **instructions)
// {
// 	t_list	*last;

// 	last = ft_lstlast(*instructions);
// 	ft_lstdelone(last, free);
// 	last = ft_lstlast(*instructions);
// 	last->next = NULL;
// }

static t_operation_type	set_operation2(t_list **instructions, t_operation_name type,
								t_operation_name prev)
{
	if (type == rra || type == rrb)
	{
		if (type == rra)
			add_operation(instructions, "rra");
		else if (type == rrb)
			add_operation(instructions, "rrb");
		return (revrotate);
	}
	else if (type == pa || (type == pb))
	{
		if (type == pa)
			add_operation(instructions, "pa");
		else if (type == pb)
			add_operation(instructions, "pb");
		return (push);
	}
	(void)prev;
	return (0);
}

static t_operation_type	set_operation(t_list **instructions, t_operation_name type,
								t_operation_name prev)
{
	(void)prev;
	if (type == sa || type == sb)
	{
		if (type == sa)
			add_operation(instructions, "sa");
		else if (type == sb)
			add_operation(instructions, "sb");
		return (swap);
	}
	else if (type == ra || type == rb)
	{
		if (type == ra)
			add_operation(instructions, "ra");
		else if (type == rb)
			add_operation(instructions, "rb");
		return (rotate);
	}
	return (set_operation2(instructions, type, prev));
}

void	exec_add_instructions(t_stack **stacksrc, t_stack **stackdst,
							t_info **info, t_operation_name op_name)
{
	static t_operation_name	prev;
	t_operation_type		op_type;

	op_type = set_operation(&(*info)->instructions, op_name, prev);
	prev = op_name;
	if (op_type == swap)
		operation_swap_one(stacksrc);
	else if (op_type == push)
		operation_push_one(stacksrc, stackdst);
	else if (op_type == rotate)
		operation_rotate_one(stacksrc);
	else if (op_type == revrotate)
		operation_revrotate_one(stacksrc);
}
