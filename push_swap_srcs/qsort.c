#include "push_swap.h"

static void	swap_for_qsort(t_stack *x, t_stack *y)
{
	t_stack		tmp;

	tmp = *y;
	*y = *x;
	*x = tmp;
}

int	get_pivot(t_stack sort_stack[], int first, int last)
{
	while (first < last)
	{
		if (sort_stack[first].elem != sort_stack[first + 1].elem)
			return (sort_stack[first].elem);
		first++;
	}
	return (-1);
}

int	partition(t_stack sort_stack[], int first, int last)
{
	int		i;
	int		j;
	int		pivot;

	i = first;
	j = last;
	pivot = get_pivot(sort_stack, first, last);
	if (pivot == -1)
		return (pivot);
	while (i < j)
	{
		while (i < last && sort_stack[i].elem < pivot)
			i++;
		while (first < j && pivot < sort_stack[j].elem)
			j--;
		if (i > j)
			break ;
		swap_for_qsort(&sort_stack[i], &sort_stack[j]);
	}
	return (i);
}

void	qsort_stack(t_stack sort_stack[], int first, int last)
{
	int		pivot;

	if (first >= last)
		return ;
	pivot = partition(sort_stack, first, last);
	if (pivot == -1)
		return ;
	qsort_stack(sort_stack, first, pivot - 1);
	qsort_stack(sort_stack, pivot + 1, last);
}
