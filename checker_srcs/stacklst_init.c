#include "push_swap.h"

void	stacklst_init(t_stack **head, int elem)
{
	t_stack		*new;

	if (!*head)
	{
		*head = stacklst_new(elem);
		if (!(*head))
			exit(EXIT_FAILURE);
	}
	else
	{
		new = stacklst_new(elem);
		if (!new)
			exit(EXIT_FAILURE);
		stacklst_add_back(head, new);
	}
}
