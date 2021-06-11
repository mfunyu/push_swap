#include "push_swap.h"

static void	swap_for_qsort(t_stack *x, t_stack *y)
{
	t_stack		tmp;

	tmp = *y;
	*y = *x;
	*x = tmp;
}

bool	get_pivot(t_stack sort_stack[], int first, int last, int *pivot)
{
	while (first < last)
	{
		if (sort_stack[first].elem > sort_stack[first + 1].elem)
		{
			*pivot = sort_stack[first].elem;
			return (false);
		}
		if (sort_stack[first].elem < sort_stack[first + 1].elem)
		{
			*pivot = sort_stack[first + 1].elem;
			return (false);
		}
		first++;
	}
	return (true);
}

int	partition(t_stack sort_stack[], int first, int last, int *pivot)
{
	int		i;
	int		j;
	bool	done;

	i = first;
	j = last;
	done = get_pivot(sort_stack, first, last, pivot);
	if (done)
		return (done);
	while (i < j)
	{
		while (i < last && sort_stack[i].elem < *pivot)
			i++;
		while (first < j && *pivot <= sort_stack[j].elem)
			j--;
		if (i >= j)
			break ;
		swap_for_qsort(&sort_stack[i], &sort_stack[j]);
	}
	*pivot = i;
	return (false);
}

void	qsort_stack(t_stack sort_stack[], int first, int last)
{
	int		pivot;
	bool	done;

	if (first >= last)
		return ;
	done = partition(sort_stack, first, last, &pivot);
	if (done)
		return ;
	qsort_stack(sort_stack, first, pivot - 1);
	qsort_stack(sort_stack, pivot, last);
}
