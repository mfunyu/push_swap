#include "push_swap.h"

void	skip_or_sort_stack_a(t_info **info, t_stack **src, t_stack **dst)
{
	if ((*src)->order == (*info)->sorted_id + 1
		&& (*src)->prev->prev->order == (*info)->sorted_id)
	{
		(*src)->sorted = 1;
		exec_add_instructions(src, dst, info, ra);
		(*info)->sorted_id++;
		return ;
	}
	else if ((*src)->order == (*info)->sorted_id + 2
		&& (*src)->next->order == (*info)->sorted_id + 1
		&& (*src)->prev->prev->order == (*info)->sorted_id)
	{
		exec_add_instructions(src, dst, info, sa);
		skip_or_sort_stack_a(info, src, dst);
		return ;
	}
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
		return ;
	}
	else if ((*src)->order == (*info)->sorted_id + 2
		&& (*src)->next->order == (*info)->sorted_id + 1)
	{
		exec_add_instructions(src, dst, info, sb);
		skip_or_sort_stack_b(info, src, dst);
		return ;
	}
	exec_add_instructions(src, dst, info, rb);
}

void	check_for_rb(t_info **info, int pivot_a)
{
	int		pivot;

	pivot = (pivot_a - (*info)->sorted_id) / 2 + (*info)->sorted_id;
	if ((*info)->stack_b->order <= pivot)
		exec_add_instructions(&(*info)->stack_b, NULL, info, rb);
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
			skip_or_sort_stack_a(info, &(*info)->stack_a, &(*info)->stack_b);
			working = (*info)->stack_a;
			continue ;
		}
		working = working->next;
		degree++;
	}
	(*info)->b_min = (*info)->sorted_id + 1;
	(*info)->b_max = pivot_a;
	(*info)->a_min = pivot_a + 1;
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
	(*info)->b_max = pivot_b;
	(*info)->b_min = (*info)->sorted_id + 1;
	(*info)->a_min = pivot_b + 1;
}
