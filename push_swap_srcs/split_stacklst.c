#include "push_swap.h"

void	skip_or_sort_stack_a(t_info **info, t_stack **src, t_stack **dst)
{
	if ((*src)->order == (*info)->sorted_id + 1
		&& (*src)->prev->prev->order == (*info)->sorted_id)
	{
		(*src)->sorted = 1;
		exec_add_instructions(src, dst, info, ra);
		(*info)->sorted_id++;
		(*info)->a_min++;
	}
	else
		exec_add_instructions(src, dst, info, pb);
}

void	skip_or_sort_stack_b(t_info **info, t_stack **src, t_stack **dst)
{
	if ((*src)->order == (*info)->sorted_id + 1)
	{
		(*src)->sorted = 1;
		exec_add_instructions(src, dst, info, pa);
		exec_add_instructions(dst, NULL, info, ra);
		(*info)->sorted_id++;
		(*info)->b_min++;
	}
	else
		exec_add_instructions(src, dst, info, rb);
}

void	split_stacklst_mv_smaller(t_info **info, int pivot_a)
{
	t_stack		*working;
	int			degree;

	degree = 0;
	working = (*info)->stack_a;
	while (!working->nil && !working->sorted)
	{
		if (working->order <= pivot_a && !working->sorted)
		{
			while (degree)
			{
				exec_add_instructions(&(*info)->stack_a, &(*info)->stack_b,
					info, ra);
				degree--;
			}
			skip_or_sort_stack_a(info, &(*info)->stack_a, &(*info)->stack_b);
			working = (*info)->stack_a;
		}
		else
		{
			working = working->next;
			degree++;
		}
	}
	(*info)->b_min = (*info)->a_min;
	(*info)->a_min = pivot_a + 1;
	(*info)->b_max = pivot_a;
}

void	split_stacklst_mv_larger(t_info **info, int pivot_b)
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
		}
		else
		{
			working = working->next;
			degree++;
		}
	}
	(*info)->b_max = pivot_b;
	(*info)->a_min = (*info)->b_max + 1;
}
