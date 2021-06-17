#include "push_swap.h"

void	sort_stack(t_info **info, t_stack_type type)
{
	int			len;
	t_stack		**src;

	if (type == A)
		src = &(*info)->stack_a;
	else
		src = &(*info)->stack_b;
	if (is_sorted((*info)->stack_a, (*info)->stack_b))
		return ;
	len = stack_count(*src);
	if (len == 1)
		return ;
	else if (len == 2)
		sort_two(src, info, type);
	else if (len == 3)
		sort_three(src, info, type);
	else if (len <= 5)
		sort_five(info);
	else
		sort_all(info);
}
