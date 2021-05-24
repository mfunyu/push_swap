#include "utils.h"

void	stacklst_insert(t_stack *first, t_stack *second, t_stack *insert)
{
	first->next = insert;
	second->prev = insert;
	insert->prev = first;
	insert->next = second;
}
