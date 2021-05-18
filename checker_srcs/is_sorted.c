#include "checker.h"

bool	is_sorted(t_stack *stack_a, t_stack *stack_b)
{
	int		prev;

	if (stack_a->nil || !stack_b->nil)
		return (false);
	prev = stack_a->elem;
	stack_a = stack_a->next;
	while (!stack_a->nil)
	{
		if (stack_a->elem < prev)
			return (false);
		stack_a = stack_a->next;
	}
	return (true);
}
