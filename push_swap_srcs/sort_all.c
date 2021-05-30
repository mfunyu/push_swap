#include "push_swap.h"

int	find_pivot(t_info **info, t_stack_type type)
{
	int			pivot;

	if (type == A)
		pivot = ((*info)->a_max - (*info)->a_min) / 2 + (*info)->a_min;
	else
	{
		pivot = ((*info)->b_max - (*info)->b_min) / 2 + (*info)->b_min;
		if (pivot < (*info)->b_min + 2 && (*info)->b_min + 2 < (*info)->b_max)
			pivot = (*info)->b_min + 2;
	}
	if (simplelst_add_front(&(*info)->pivot, pivot) == ERROR)
		clear_exit(&(*info)->stack_a, &(*info)->stack_b, info, true);
	return (pivot);
}

void	sort_stack_b(t_info **info)
{
	if ((*info)->stack_b->nil || (*info)->b_max < (*info)->b_min)
		return ;
	if (((*info)->b_max - (*info)->b_min) + 1 <= 3)
	{
		while (!(*info)->stack_b->nil)
		{
			exec_add_instructions(&(*info)->stack_b, &(*info)->stack_a,
				info, pa);
			while ((*info)->stack_a->order == (*info)->sorted_id + 1)
			{
				(*info)->stack_a->sorted = 1;
				exec_add_instructions(&(*info)->stack_a, NULL, info, ra);
				(*info)->sorted_id++;
			}
		}
		(*info)->b_max = -1;
		(*info)->b_min = -1;
		(*info)->a_min = (*info)->sorted_id + 1;
		return ;
	}
	split_stack_b(info, find_pivot(info, B));
	sort_stack_b(info);
}

/*
** sort stack_a and push some to stack_b
*/
void	sort_all(t_info **info)
{
	int			pivot;
	t_simple	*now;

	split_stack_a(info, find_pivot(info, A));
	while (!is_sorted((*info)->stack_a, (*info)->stack_b))
	{
		sort_stack_b(info);
		pivot = (*info)->a_len;
		now = (*info)->pivot;
		while (now)
		{
			if (now->value > (*info)->a_min)
			{
				pivot = now->value;
				break ;
			}
			now = now->next;
		}
		if (!is_sorted((*info)->stack_a, (*info)->stack_b))
			split_stack_a(info, pivot);
	}
}
