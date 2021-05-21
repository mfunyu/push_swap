#include "push_swap.h"

bool	stack_b_push_back(t_stack **stack_b, t_stack **stack_a,
									t_info **info, t_stack_info *st_info)
{
	bool	pivot_done;

	pivot_done = false;
	while (!(*stack_b)->nil)
	{
		if ((*stack_b)->elem == st_info->pivot)
			pivot_done = true;
		ps_print_stack(*info, "pushback");
		exec_add_instructions(stack_b, stack_a, info, pa);
		exec_add_instructions(stack_a, NULL, info, ra);
	}
	return (pivot_done);
}
