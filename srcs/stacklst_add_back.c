#include "utils.h"

void	stacklst_add_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		last = stacklst_last(*lst);
		last->next = new;
		new->prev = last;
	}
}
