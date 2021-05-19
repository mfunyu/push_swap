#include "push_swap.h"

void	sort_stack(t_stack **stack_a, t_stack **stack_b, t_list **instructions)
{
	int		len;

	len = count_stacklst(*stack_a);
	*instructions = NULL;
	if (len == 1)
		return ;
	if (len == 2)
		sort_two(stack_a, instructions, A);
	if (len == 3)
		sort_three(stack_a, instructions);
	(void)stack_b;
}
