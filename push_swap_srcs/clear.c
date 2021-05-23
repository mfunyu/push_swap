#include "push_swap.h"

void	free_t_instruct(t_instruc **used)
{
	t_instruc	*now;
	t_instruc	*tmp;

	if (!used || !*used)
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
	free_t_instruct(&(*info)->pivot);
	stacklst_clear(&(*info)->stack_a);
	stacklst_clear(&(*info)->stack_b);
	null_free((void **)info);
}

void	clear_exit(t_stack **stack1, t_stack **stack2, t_info **info, bool set)
{
	if (!set)
	{
		stacklst_clear(stack1);
		stacklst_clear(stack2);
	}
	clear_info(info);
	exit(EXIT_FAILURE);
}
