#include "checker.h"

void	stacklst_add_front(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	(*lst)->prev = new;
}
