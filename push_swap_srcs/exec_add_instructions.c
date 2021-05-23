#include "push_swap.h"

static t_operation_type	set_operation_revrotate(t_instruc **instructions,
			t_operation_name type, t_operation_name prev)
{
	int		ret;

	ret = 0;
	if (type == rra || type == rrb)
	{
		if (type == rra && prev != ra && prev != rrb)
			ret = simplelst_add_back(instructions, rra);
		else if (type == rrb && prev != rb && prev != rra)
			ret = simplelst_add_back(instructions, rrb);
		else
		{
			simplelst_pop(instructions);
			if (prev == rra || prev == rrb)
				ret = simplelst_add_back(instructions, rrr);
		}
		if (ret)
			return (ERROR);
		return (revrotate);
	}
	return (ERROR);
}

static t_operation_type	set_operation_push(t_instruc **instructions,
							t_operation_name type, t_operation_name prev)
{
	int		ret;

	ret = 0;
	if (type == pa || type == pb)
	{
		if (type == pa && prev != pb)
			ret = simplelst_add_back(instructions, pa);
		else if (type == pb && prev != pa)
			ret = simplelst_add_back(instructions, pb);
		else
			simplelst_pop(instructions);
		if (ret)
			return (ERROR);
		return (push);
	}
	return (set_operation_revrotate(instructions, type, prev));
}

static t_operation_type	set_operation_rotate(t_instruc **instructions,
							t_operation_name type, t_operation_name prev)
{
	int		ret;

	ret = 0;
	if (type == ra || type == rb)
	{
		if (type == ra && prev != rra && prev != rb)
			ret = simplelst_add_back(instructions, ra);
		else if (type == rb && prev != rrb && prev != ra)
			ret = simplelst_add_back(instructions, rb);
		else
		{
			simplelst_pop(instructions);
			if (prev == ra || prev == rb)
				ret = simplelst_add_back(instructions, rr);
		}
		if (ret)
			return (ERROR);
		return (rotate);
	}
	return (set_operation_push(instructions, type, prev));
}

static t_operation_type	set_operation_swap(t_instruc **instructions,
								t_operation_name type, t_operation_name prev)
{
	int		ret;

	ret = 0;
	if (type == sa || type == sb)
	{
		if (type == sa && prev != sb)
			ret = simplelst_add_back(instructions, sa);
		else if (type == sb && prev != sa)
			ret = simplelst_add_back(instructions, sb);
		else
		{
			simplelst_pop(instructions);
			ret = simplelst_add_back(instructions, ss);
		}
		if (ret)
			return (ERROR);
		return (swap);
	}
	return (set_operation_rotate(instructions, type, prev));
}

void	exec_add_instructions(t_stack **stacksrc, t_stack **stackdst,
								t_info **info, t_operation_name op_name)
{
	t_operation_name	prev;
	t_operation_type	op_type;
	t_instruc			*last;

	last = (*info)->instructions;
	if (!last)
		prev = -1;
	else
	{
		while (last->next)
			last = last->next;
		prev = last->operation;
	}
	op_type = set_operation_swap(&(*info)->instructions, op_name, prev);
	if ((int)op_type == ERROR)
		clear_exit(stacksrc, stackdst, info, true);
	if (op_type == swap)
		operation_swap_one(stacksrc);
	else if (op_type == push)
		operation_push_one(stacksrc, stackdst);
	else if (op_type == rotate)
		operation_rotate_one(stacksrc);
	else if (op_type == revrotate)
		operation_revrotate_one(stacksrc);
	prev = op_name;
}
