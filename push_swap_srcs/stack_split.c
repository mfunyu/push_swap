#include "push_swap.h"

void	check_for_rb(t_info **info, int pivot_a)
{
	int		pivot;

	pivot = (pivot_a - (*info)->sorted_id) / 2 + (*info)->sorted_id;
	if ((*info)->stack_b->order <= pivot)
		exec_add_instructions(&(*info)->stack_b, NULL, info, rb);
}

void	update_max_min(t_info **info, int pivot, t_stack_type type)
{
	if (type == A)
	{
		(*info)->b_min = (*info)->sorted_id + 1;
		(*info)->b_max = pivot;
		(*info)->a_min = pivot + 1;
	}
	else if (type == B)
	{
		(*info)->b_max = pivot;
		(*info)->b_min = (*info)->sorted_id + 1;
		(*info)->a_min = pivot + 1;
	}
}

void	split_stack_a(t_info **info, int pivot_a)
{
	t_stack		*working;
	int			degree;

	degree = 0;
	working = (*info)->stack_a;
	while (!working->nil && !working->sorted)
	{
		if (working->order <= pivot_a && !working->sorted)
		{
			while (degree > 0)
			{
				exec_add_instructions(&(*info)->stack_a, &(*info)->stack_b,
					info, ra);
				check_for_rb(info, pivot_a);
				degree--;
			}
			push_or_sort_stack_a(info, &(*info)->stack_a, &(*info)->stack_b);
			working = (*info)->stack_a;
			continue ;
		}
		working = working->next;
		degree++;
	}
	update_max_min(info, pivot_a, A);
}

void	split_stack_b(t_info **info, int pivot_b)
{
	t_stack		*working;
	int			degree;

	degree = 0;
	working = (*info)->stack_b;
	while (!working->nil)
	{
		if (working->order > pivot_b)
		{
			while (degree)
			{
				skip_or_sort_stack_b(info, &(*info)->stack_b,
					&(*info)->stack_a);
				degree--;
			}
			exec_add_instructions(&(*info)->stack_b, &(*info)->stack_a,
				info, pa);
			working = (*info)->stack_b;
			continue ;
		}
		working = working->next;
		degree++;
	}
	update_max_min(info, pivot_b, B);
}
