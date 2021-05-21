#include "push_swap.h"

void	clear_info(t_info **info)
{
	ft_lstclear(&((*info)->instructions), free);
	stacklst_clear(&(*info)->stack_a);
	stacklst_clear(&(*info)->stack_b);
	free(*info);
	*info = NULL;
}
