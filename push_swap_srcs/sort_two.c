#include "push_swap.h"

/*
** can be used by both stack_a and stack_b
*/
void	sort_two(t_stack **stack, t_info **info, t_stack_type type)
{
	t_stack				*first;
	t_operation_name	operation;

	first = *stack;
	if (first->elem < first->next->elem)
		return ;
	if (type == A)
		operation = sa;
	else
		operation = sb;
	exec_add_instructions(stack, NULL, info, operation);
}
