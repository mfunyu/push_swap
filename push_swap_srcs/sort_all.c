#include "push_swap.h"

int	find_pivot(t_info **info, t_stack_type type)
{
	int			pivot;
	t_instruc	*new;

	if (type == A)
		pivot = ((*info)->a_max - (*info)->a_min) / 2 + (*info)->a_min;
	else
	{
		pivot = ((*info)->b_max - (*info)->b_min) / 2 + (*info)->b_min;
		if (pivot < (*info)->b_min + 2 && (*info)->b_min + 2 < (*info)->b_max)
			pivot = (*info)->b_min + 2;
	}
	new = malloc(sizeof(t_instruc));
	new->operation = pivot;
	new->next = (*info)->pivot;
	(*info)->pivot = new;
	return (pivot);
}

int	sort_stack_b(t_info **info)
{
	int		pivot_b;
	// int		next_pivot;

	if ((*info)->stack_b->nil || (*info)->b_max < (*info)->b_min)
		return (-2);
	if (((*info)->b_max - (*info)->b_min) + 1 <= 3)
	{
		// printf("\nwillbmax: %d min: %d\n", (*info)->b_max, (*info)->b_min);
		ps_print_stack(*info, "b will be sorted", 0);
		sort_stack(info, B);
		ps_print_stack(*info, "b sorted", 0);
		return (-1);
	}
	pivot_b = find_pivot(info, B);
	ps_print_stack(*info, "b moved", 0);
	split_stacklst_mv_larger(info, pivot_b);
	pivot_b = sort_stack_b(info);
	return (pivot_b);
}

/*
** sort stack_a and push some to stack_b
*/
void	sort_all(t_info **info)
{
	int			pivot_a;
	int			pivot;
	t_instruc	*now;

	(*info)->pivot = NULL;
	pivot_a = find_pivot(info, A);
	split_stacklst_mv_smaller(info, pivot_a);
	while (!is_sorted((*info)->stack_a, (*info)->stack_b))
	{
		sort_stack_b(info);
		stack_b_push_back(info);
		ps_print_stack(*info, "round end", 0);
		pivot = -1;
		now = (*info)->pivot;
		while (now)
		{
			if ((int)now->operation > (*info)->a_min)
			{
				pivot = now->operation;
				break ;
			}
			now = now->next;
		}
		if (pivot == -1)
			pivot = (*info)->a_len;
		if (!is_sorted((*info)->stack_a, (*info)->stack_b))
			split_stacklst_mv_smaller(info, pivot);
	}
	free_t_instruct(&(*info)->pivot);
}
