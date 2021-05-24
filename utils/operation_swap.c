#include "utils.h"

void	operation_swap_one(t_stack **stack)
{
	t_stack		*head;

	head = stacklst_pop(stack, true);
	stacklst_insert(*stack, (*stack)->next, head);
}

void	operation_swap_both(t_stack **stack_a, t_stack **stack_b)
{
	operation_swap_one(stack_a);
	operation_swap_one(stack_b);
}
