#include "push_swap.h"

void	sort_three(t_stack **stack_a, t_list **instructions, t_stack_type type)
{
	t_stack	*first;
	t_stack	*second;

	first = *stack_a;
	second = (*stack_a)->next;
	if (first->order == 0 && second->order == 1)
		return ;
	else if (first->order == 1 && second->order == 2)
		exec_add_instructions(stack_a, NULL, instructions, rra + type);
	else if (first->order == 2 && second->order == 0)
		exec_add_instructions(stack_a, NULL, instructions, ra + type);
	else
	{
		exec_add_instructions(stack_a, NULL, instructions, sa + type);
		sort_three(stack_a, instructions, type);
	}
}
