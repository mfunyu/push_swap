#include "push_swap.h"

void	sort_three(t_stack **stack_a, t_list **instructions)
{
	int		first;
	int		middle;
	int		last;

	first = (*stack_a)->elem;
	middle = (*stack_a)->next->elem;
	last = (*stack_a)->next->next->elem;
	if (first < middle && middle < last)
		return ;
	else if (last < first && first < middle)
		exec_add_instructions(stack_a, NULL, instructions, rra);
	else if (middle < last && last < first)
		exec_add_instructions(stack_a, NULL, instructions, ra);
	else
	{
		exec_add_instructions(stack_a, NULL, instructions, sa);
		sort_three(stack_a, instructions);
	}
}
