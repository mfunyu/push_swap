#include "push_swap.h"

/*
** only work with stack_a
*/
void	sort_five(t_info **info)
{
	int			count;

	count = 0;
	while (!(*info)->stack_a->nil && count < 2
		&& !is_sorted((*info)->stack_a, NULL))
	{
		if ((*info)->stack_a->order <= (*info)->a_min + 1)
		{
			exec_add_instructions(&(*info)->stack_a, &(*info)->stack_b,
				info, pb);
			count++;
		}
		else
			exec_add_instructions(&(*info)->stack_a, NULL, info, ra);
	}
	if (!is_sorted((*info)->stack_a, NULL))
	{
		(*info)->a_min = 2;
		sort_three(&(*info)->stack_a, info, A);
	}
	while (!(*info)->stack_b->nil)
		exec_add_instructions(&(*info)->stack_b, &(*info)->stack_a,
			info, pa);
	if ((*info)->stack_a->order != 0)
		exec_add_instructions(&(*info)->stack_a, NULL, info, sa);
}
