#include "push_swap.h"

void	split_stacklst_mv_smaller(t_info **info, int pivot_a)
{
	t_stack		*working;
	t_stack		**src;
	t_stack		**dst;
	int			degree;

	src = &(*info)->stack_a;
	dst = &(*info)->stack_b;
	degree = 0;
	working = *src;
	// printf("piv: [%d]\n", pivot_a);
	while (!working->nil && !working->sorted)
	{
		if (working->order <= pivot_a && !working->sorted)
		{
			while (degree)
			{
				degree--;
				exec_add_instructions(src, dst, info, ra);
			}
			if (working->order == (*info)->sorted_id + 1 && (*src)->prev->prev->order == (*info)->sorted_id)
			{
				exec_add_instructions(src, dst, info, ra);
				working->sorted = 1;
				(*info)->sorted_id++;
				(*info)->a_min++;
			}
			else
				exec_add_instructions(src, dst, info, pb);
			working = *src;
		}
		else
		{
			working = working->next;
			degree++;
		}
	}
	ps_print_stack(*info, "pb", 0);
	(*info)->b_min = (*info)->a_min;
	(*info)->a_min = pivot_a + 1;
	(*info)->b_max = pivot_a;
	if (!is_ordered(*src))
	{
		working = *src;
		while ((*info)->sorted_id != -1 && (*src)->prev->prev->order != (*info)->sorted_id)
		{
			exec_add_instructions(src, dst, info, ra);
			working = *src;
		}
	}
	ps_print_stack(*info, "pb", 0);
	// printf("\n\nbmax: %d min: %d\n", (*info)->b_max, (*info)->b_min);
}

void	split_stacklst_mv_larger(t_info **info, int pivot_b)
{
	t_stack		*working;
	t_stack		**src;
	t_stack		**dst;
	int			degree;

	src = &(*info)->stack_b;
	dst = &(*info)->stack_a;
	degree = 0;
	working = *src;
	while (!working->nil)
	{
		if (working->order > pivot_b)
		{
			while (degree)
			{
				degree--;
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
			exec_add_instructions(src, dst, info, pa);
			working = *src;
		}
		else
		{
			working = working->next;
			degree++;
		}
	}
	(*info)->b_max = pivot_b;
	(*info)->a_min = (*info)->b_max + 1;
	ps_print_stack(*info, "pa", 0);
	// printf("\n\nbmax: %d min: %d \n", (*info)->b_max, (*info)->b_min);
}
