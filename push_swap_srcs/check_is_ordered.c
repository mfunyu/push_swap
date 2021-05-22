#include "push_swap.h"

bool	is_ordered(t_stack *stack_a)
{
	int		index;

	index = 0;
	if (!stack_a)
		return (false);
	while (!stack_a->nil)
	{
		if (stack_a->order != index)
			return (false);
		stack_a = stack_a->next;
		index++;
	}
	return (true);
}
