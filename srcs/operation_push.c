#include "checker.h"

void	operation_push_one(t_stack **src, t_stack **dest)
{
	t_stack		*head;

	if ((*src)->nil)
		return ;
	head = stacklst_pop(src, true);
	stacklst_insert((*dest)->prev, *dest, head);
	*dest = head;
}
