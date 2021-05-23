#include "push_swap.h"

bool	stack_b_push_a(t_info **info)
{
	bool	pivot_done;

	pivot_done = false;
	while (!(*info)->stack_b->nil)
	{
		if ((*info)->stack_b->order == (*info)->b_max)
			pivot_done = true;
		(*info)->stack_b->sorted = 1;
		(*info)->sorted_id = (*info)->stack_b->order;
		exec_add_instructions(&(*info)->stack_b, &(*info)->stack_a, info, pa);
		exec_add_instructions(&(*info)->stack_a, NULL, info, ra);
	}
	return (pivot_done);
}
