#include "utils.h"

void	operation_rotate_one(t_stack **stack)
{
	t_stack		*head;
	t_stack		*last;

	if ((*stack)->nil || (*stack)->next->nil)
		return ;
	head = stacklst_pop(stack, true);
	last = (*stack)->prev->prev;
	stacklst_insert(last, last->next, head);
}

void	operation_rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	operation_rotate_one(stack_a);
	operation_rotate_one(stack_b);
}
