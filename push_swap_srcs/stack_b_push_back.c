#include "push_swap.h"

bool	stack_b_push_back(t_info **info, int pivot_a)
{
	bool	pivot_done;

	pivot_done = false;
	ps_print_stack(*info, "push", 0);
	while (!(*info)->stack_b->nil)
	{
		if ((*info)->stack_b->order == pivot_a - 1)
			pivot_done = true;
		(*info)->stack_b->sorted = 1;
		(*info)->sorted_id = (*info)->stack_b->order;
		ps_print_stack(*info, "pushback", -1);
		exec_add_instructions(&(*info)->stack_b, &(*info)->stack_a, info, pa);
		exec_add_instructions(&(*info)->stack_a, NULL, info, ra);
	}
	// add largest sorted in t_info
	return (pivot_done);
}
