#include "push_swap.h"

static void	add_operation(t_instruc **instructions, t_operation_name name)
{
	t_instruc	*last;
	t_instruc	*new;

	new = malloc(sizeof(t_instruc));
	new->operation = name;
	new->next = NULL;
	if (!new)
		exit(EXIT_FAILURE);
	if (*instructions == NULL)
		*instructions = new;
	else
	{
		last = *instructions;
		while (last->next)
			last = last->next;
		last->next = new;
	}
}

static void	rmv_operation(t_instruc **instructions)
{
	t_instruc	*last;

	last = *instructions;
	while (last->next->next)
		last = last->next;
	free(last->next);
	last->next = NULL;
}

static t_operation_type	set_operation2(t_instruc **instructions, t_operation_name type,
								t_operation_name prev)
{
	if (type == rra || type == rrb)
	{
		if (type == rra && prev != ra && prev != rrb)
			add_operation(instructions, rra);
		else if (type == rrb && prev != rb && prev != rra)
			add_operation(instructions, rrb);
		else
		{
			rmv_operation(instructions);
			if (prev == rra || prev == rrb)
				add_operation(instructions, rrr);
		}
		return (revrotate);
	}
	else if (type == pa || type == pb)
	{
		if (type == pa && prev != pb)
			add_operation(instructions, pa);
		else if (type == pb && prev != pa)
			add_operation(instructions, pb);
		else
			rmv_operation(instructions);
		return (push);
	}
	return (0);
}

static t_operation_type	set_operation(t_instruc **instructions, t_operation_name type,
								t_operation_name prev)
{
	if (type == sa || type == sb)
	{
		if (type == sa && prev != sb)
			add_operation(instructions, sa);
		else if (type == sb && prev != sa)
			add_operation(instructions, sb);
		else
		{
			rmv_operation(instructions);
			add_operation(instructions, ss);
		}
		return (swap);
	}
	else if (type == ra || type == rb)
	{
		if (type == ra && prev != rra && prev != rb)
			add_operation(instructions, ra);
		else if (type == rb && prev != rrb && prev != ra)
			add_operation(instructions, rb);
		else
		{
			rmv_operation(instructions);
			if (prev == ra || prev == rb)
				add_operation(instructions, rr);
		}
		return (rotate);
	}
	return (set_operation2(instructions, type, prev));
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
