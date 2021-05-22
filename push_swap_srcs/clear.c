#include "push_swap.h"

void	free_t_instruct(t_instruc **used)
{
	t_instruc	*now;
	t_instruc	*tmp;

	if (!used)
		return ;
	now = *used;
	while (now)
	{
		tmp = now;
		now = now->next;
		free(tmp);
	}
}

void	clear_info(t_info **info)
{
	free_t_instruct(&(*info)->instructions);
	stacklst_clear(&(*info)->stack_a);
	stacklst_clear(&(*info)->stack_b);
	null_free((void **)info);
}

void	clear_exit(t_stack **stack_a, t_stack **stack_b, t_info **info, t_instruc **instructions)
{
	free_t_instruct(instructions);
	stacklst_clear(stack_a);
	stacklst_clear(stack_b);
	null_free((void **)info);
	exit(EXIT_FAILURE);
}
