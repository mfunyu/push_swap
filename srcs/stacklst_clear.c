#include "utils.h"

void	stacklst_clear(t_stack **lst)
{
	t_stack	*next;

	if (!lst || !*lst)
		return ;
	if ((*lst)->prev)
		(*lst)->prev->next = NULL;
	while (*lst)
	{
		next = (*lst)->next;
		free(*lst);
		*lst = next;
	}
	lst = NULL;
}
