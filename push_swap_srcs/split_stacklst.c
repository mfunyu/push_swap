#include "push_swap.h"

void	split_stacklst(t_stack **src, t_stack **dst,
							t_info **info, t_stack_info *st_info)
{
	t_stack		*working;
	int			degree;

	degree = 0;
	working = *src;
	printf("piv: %d\n", st_info->pivot);
	while (!working->nil)
	{
		if (working->elem < st_info->pivot)
		{
			while (degree)
			{
				degree--;
				exec_add_instructions(src, dst, info, ra + st_info->type);
			}
			exec_add_instructions(src, dst, info, pa + st_info->type);
			working = *src;
		}
		else
		{
			working = working->next;
			degree++;
		}
	}
	ps_print_stack(*info, "ra");
}

void	split_stacklst_b(t_stack **src, t_stack **dst, t_info **info,
														t_stack_info *st_info)
{
	t_stack		*working;
	int			degree;

	degree = 0;
	working = *src;
	printf("piv: %d\n", st_info->pivot);
	while (!working->nil)
	{
		if (working->elem > st_info->pivot)
		{
			while (degree)
			{
				degree--;
				exec_add_instructions(src, dst, info, ra + st_info->type);
				// print_stack(*dst, *src, "ra");
			}
			exec_add_instructions(src, dst, info, pa + st_info->type);
			working = *src;
		}
		else
		{
			working = working->next;
			degree++;
		}
	}
	ps_print_stack(*info, "split B");
}
