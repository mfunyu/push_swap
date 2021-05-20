#include "push_swap.h"

void	sort_three(t_stack **stack, t_info *info, t_stack_type type)
{
	t_stack	*first;
	t_stack	*second;
	int		min;
	int		max;

	min = info->b_min;
	max = info->b_max;
	if (type == A)
	{
		min = info->a_min;
		max = info->a_max;
	}
	first = *stack;
	second = (*stack)->next;
	if (first->order == min && second->next->order == max)
		return ;
	else if (second->next->order == min && second->order == max)
		exec_add_instructions(stack, NULL, info, rra + type);
	else if (first->order == max && second->order == min)
		exec_add_instructions(stack, NULL, info, ra + type);
	else
	{
		exec_add_instructions(stack, NULL, info, sa + type);
		sort_three(stack, info, type);
	}
}
