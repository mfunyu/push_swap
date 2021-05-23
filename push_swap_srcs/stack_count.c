#include "push_swap.h"

int	stack_count(t_stack *lst)
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
