#include "push_swap.h"

int	count_stacklst(t_stack *lst)
{
	int		count;

	count = 0;
	while (!lst->nil)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
