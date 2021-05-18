#include "checker.h"

void	operation_revrotate_one(t_stack **stack)
{
	t_stack		*last;

	if ((*stack)->nil || (*stack)->next->nil)
		return ;
	last = stacklst_pop(stack, false);
	stacklst_insert((*stack)->prev, *stack, last);
	*stack = last;
}

void	operation_revrotate_both(t_stack **stack_a, t_stack **stack_b)
{
	operation_revrotate_one(stack_a);
	operation_revrotate_one(stack_b);
}
