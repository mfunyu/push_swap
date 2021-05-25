#include "push_swap.h"

int	get_index_smallest_a(t_stack *stack_a, t_info **info)
{
	int		index;

	index = 0;
	while (!stack_a->nil)
	{
		if (stack_a->order == (*info)->a_min)
			return (index);
		index++;
		stack_a = stack_a->next;
	}
	return (-1);
}

/*
** only work with stack_a
*/
void	sort_five(t_info **info, int len)
{
	int					s_index;
	t_op_name	direction;

	if (is_sorted((*info)->stack_a, (*info)->stack_b))
		return ;
	if (len == 3)
	{
		sort_three(&(*info)->stack_a, info, A);
		while (!(*info)->stack_b->nil)
			exec_add_instructions(&(*info)->stack_b, &(*info)->stack_a,
				info, pa);
		return ;
	}
	s_index = get_index_smallest_a((*info)->stack_a, info);
	direction = ra;
	if (s_index >= len / 2)
	{
		direction = rra;
		s_index = len - s_index;
	}
	while (s_index--)
		exec_add_instructions(&(*info)->stack_a, NULL, info, direction);
	exec_add_instructions(&(*info)->stack_a, &(*info)->stack_b, info, pb);
	(*info)->a_min++;
	sort_five(info, len - 1);
}
