#include "push_swap.h"

int	find_pivot(t_info **info, t_stack_type type)
{
	int		pivot;

	if (type == A)
		pivot = ((*info)->a_max - (*info)->a_min) / 2 + (*info)->a_min;
	else
	{
		pivot = ((*info)->b_max - (*info)->b_min) / 2 + (*info)->b_min;
		// pivot = (*info)->b_min + 2;
		// if (pivot > (*info)->b_max)
		// 	pivot = (*info)->b_max;
	}
	return (pivot);
}

void	sort_stack_b(t_info **info)
{
	int		pivot_b;

	if ((*info)->stack_b->nil)
		return ;
	if (((*info)->b_max - (*info)->b_min) + 1 <= 3)
	{
		ps_print_stack(*info, "b will be sorted", 0);
		sort_stack(info, B);
		ps_print_stack(*info, "b sorted", 0);
	}
	else
	{
		pivot_b = find_pivot(info, B);
		split_stacklst_mv_larger(info, pivot_b);
		sort_stack_b(info);
	}
}

/*
** sort stack_a and push some to stack_b
*/
void	sort_all(t_info **info)
{
	int		pivot_a;

	pivot_a = find_pivot(info, A);
	split_stacklst_mv_smaller(info, pivot_a);
	sort_stack_b(info);
	stack_b_push_back(info, pivot_a);
	ps_print_stack(*info, "round end", 0);
	// working = *stack_b;
	// while (!working->nil)
	// {
	// 	exec_add_instructions(stack_b, stack_a, instructions, pa);
	// 	exec_add_instructions(stack_b, stack_a, instructions, ra);
	// 	working = working->next;
	// }
	// print_stack(*stack_a, *stack_b, "split a2");
	// free(info);
}
