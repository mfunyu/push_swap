#include "utils.h"

t_stack	*stacklst_pop(t_stack **lst, bool head)
{
	t_stack		*pop;

	if (head)
	{
		pop = *lst;
		*lst = pop->next;
	}
	else
		pop = (*lst)->prev->prev;
	pop->prev->next = pop->next;
	pop->next->prev = pop->prev;
	return (pop);
}
