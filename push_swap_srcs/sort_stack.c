#include "push_swap.h"

void	sort_stack(t_stack **stack_a, t_stack **stack_b, t_list **instructions)
{
	int		len;

	len = count_stacklst(*stack_a);
	*instructions = NULL;
	if (len == 1)
		return ;
	else if (len == 2)
		sort_two(stack_a, instructions, A);
	else if (len == 3)
		sort_three(stack_a, instructions);
	else if (len <= 6)
		sort_six(stack_a, stack_b, instructions, len);
	else
	{

	}
}
