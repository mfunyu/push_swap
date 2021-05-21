#include "push_swap.h"

void	clear_info(t_info **info)
{
	t_instruc	*now;
	t_instruc	*tmp;

	now = (*info)->instructions;
	while (now)
	{
		tmp = now;
		now = now->next;
		free(tmp);
	}
	stacklst_clear(&(*info)->stack_a);
	stacklst_clear(&(*info)->stack_b);
	free(*info);
	*info = NULL;
}
