#include "checker.h"

void	execute_operation(char *operation, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strncmp(operation, "sa", 3) == 0)
		operation_swap_one(stack_a);
	else if (ft_strncmp(operation, "sb", 3) == 0)
		operation_swap_one(stack_b);
	else if (ft_strncmp(operation, "ss", 3) == 0)
		operation_swap_both(stack_a, stack_b);
	else if (ft_strncmp(operation, "pa", 3) == 0)
		operation_push_one(stack_b, stack_a);
	else if (ft_strncmp(operation, "pb", 3) == 0)
		operation_push_one(stack_a, stack_b);
	else if (ft_strncmp(operation, "ra", 3) == 0)
		operation_rotate_one(stack_a);
	else if (ft_strncmp(operation, "rb", 3) == 0)
		operation_rotate_one(stack_b);
	else if (ft_strncmp(operation, "rr", 3) == 0)
		operation_rotate_both(stack_a, stack_b);
	else if (ft_strncmp(operation, "rra", 4) == 0)
		operation_revrotate_one(stack_a);
	else if (ft_strncmp(operation, "rrb", 4) == 0)
		operation_revrotate_one(stack_b);
	else if (ft_strncmp(operation, "rrr", 4) == 0)
		operation_revrotate_both(stack_a, stack_b);
}

int	execute_instructions(t_stack **stack_a, t_list *instructions)
{
	t_stack		*stack_b;
	t_list		*operation;

	stack_b = stacklst_nil();
	operation = instructions;
	while (operation)
	{
		execute_operation(operation->content, stack_a, &stack_b);
		print_stack(*stack_a, stack_b, operation->content);
		operation = operation->next;
	}
	ft_lstclear(&instructions, free);
	stacklst_clear(stack_a);
	stacklst_clear(&stack_b);
	return (0);
}
