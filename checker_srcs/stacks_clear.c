#include "checker.h"

void	clear_all(t_stack **stack_a, t_stack **stack_b, t_list **instructions)
{
	ft_lstclear(instructions, free);
	stacklst_clear(stack_a);
	stacklst_clear(stack_b);
}

int	clear_return(t_stack **stack1, t_stack **stack2)
{
	stacklst_clear(stack1);
	stacklst_clear(stack2);
	ft_putendl_fd("Error", STDERR_FILENO);
	return (ERROR);
}

void	clear_exit(t_stack **stack1, t_stack **stack2)
{
	stacklst_clear(stack1);
	stacklst_clear(stack2);
	exit(EXIT_FAILURE);
}
