#include "push_swap.h"

void	push_or_sort_stack_a(t_info **info, t_stack **src, t_stack **dst)
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
		push_or_sort_stack_a(info, src, dst);
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
