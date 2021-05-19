#include "push_swap.h"

int	get_index_smallest(t_stack *stack)
{
	int		smallest;
	int		s_index;
	int		i;

	i = 0;
	s_index = 0;
	smallest = stack->elem;
	stack = stack->next;
	while (i++ < 5 && !stack->nil)
	{
		if (stack->elem < smallest)
		{
			smallest = stack->elem;
			s_index = i;
		}
		stack = stack->next;
	}
	return (s_index);
}

void	sort_six(t_stack **stack_a, t_stack **stack_b, t_list **instructions, int len)
{
	int		s_index;

	if (is_sorted(*stack_a, *stack_b))
		return ;
	if (len == 3)
	{
		sort_three(stack_a, instructions);
		while (!(*stack_b)->nil)
			exec_add_instructions(stack_b, stack_a, instructions, pa);
	}
	else
	{
		s_index = get_index_smallest(*stack_a);
		while (s_index--)
			exec_add_instructions(stack_a, NULL, instructions, ra);
		exec_add_instructions(stack_a, stack_b, instructions, pb);
		sort_six(stack_a, stack_b, instructions, len - 1);
	}
}
