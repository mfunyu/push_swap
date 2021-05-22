#include "push_swap.h"

void	sort_stack(t_info **info, t_stack_type type)
{
	int			len;
	t_stack		**src;

	if (type == A)
		src = &(*info)->stack_a;
	else
		src = &(*info)->stack_b;
	len = count_stacklst(*src);
	if (len == 1)
		return ;
	else if (len == 2)
		sort_two(src, info, type);
	else if (len == 3)
		sort_three(src, info, type);
	else if (len <= 5)
		sort_five(info, len);
	else
		sort_all(info);
}

/*
A基準値決める
* Bに基準値以下push
* Bが3以下になるまで
** B基準値決める
** B基準値以上Aにpush
* なったら
** BをAにpush (pa, ra)
*/
