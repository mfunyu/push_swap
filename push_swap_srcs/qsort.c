#include "push_swap.h"

static void	swap_for_qsort(t_stack *x, t_stack *y)
{
	t_stack		tmp;

	tmp = *y;
	*y = *x;
	*x = tmp;
}

void	qsort_stack(t_stack sort_stack[], int first, int last)
{
	int		i;
	int		j;
	int		pivot;

	if (first < last)
	{
		i = first;
		j = last;
		pivot = first;
		while (i < j)
		{
			while (sort_stack[i].elem <= sort_stack[pivot].elem)
				i++;
			while (sort_stack[pivot].elem < sort_stack[j].elem)
				j--;
			if (i < j)
				swap_for_qsort(&sort_stack[i], &sort_stack[j]);
		}
		swap_for_qsort(&sort_stack[pivot], &sort_stack[j]);
		pivot = j;
		qsort_stack(sort_stack, first, pivot - 1);
		qsort_stack(sort_stack, pivot + 1, last);
	}
}
