#include "push_swap.h"

void		sort_stack(t_info **info, t_stack_type type)
{
	int			len;

	(void)type;
	(void)info;
	// printf("%d\n", (*info)->stack_a->elem);
	// print_stack(*(*info)->stack_a, NULL, "in");
	// print_stack2(*info, "in");
	len = count_stacklst((*info)->stack_a);
	if (len == 1)
		return ;
	else if (len == 2)
		sort_two(&(*info)->stack_a, info, type);
	else if (len == 3)
		sort_three(&(*info)->stack_a, info, type);
	// else if (len <= 5)
	// 	sort_five(info, len);
	// else
	// {
	// 	// while (!is_sorted(*stack_a, *stack_b))
	// 	sort_all(info, len);
	// }
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
