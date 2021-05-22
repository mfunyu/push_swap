#include "utils.h"

t_stack	*stacklst_new(int elem)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->elem = elem;
	new->order = -1;
	new->sorted = 0;
	new->prev = NULL;
	new->next = NULL;
	new->nil = 0;
	return (new);
}

t_stack	*stacklst_nil(void)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->elem = 0;
	new->prev = new;
	new->next = new;
	new->order = -1;
	new->sorted = -1;
	new->nil = 1;
	return (new);
}
