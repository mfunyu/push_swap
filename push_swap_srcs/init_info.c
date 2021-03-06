#include "push_swap.h"

void	init_t_info(t_info **info, int a_index,
									t_stack **stack_a, t_stack **stack_b)
{
	*info = malloc(sizeof(t_info));
	if (!*info)
		clear_exit(stack_a, stack_b, NULL, false);
	(*info)->b_min = 0;
	(*info)->b_max = 0;
	(*info)->a_min = 0;
	(*info)->a_max = a_index;
	(*info)->a_len = a_index;
	(*info)->sorted_id = -1;
	(*info)->stack_a = *stack_a;
	(*info)->stack_b = *stack_b;
	(*info)->instructions = NULL;
	(*info)->pivot = NULL;
}

int	init_info(t_info **info, char **av, int ac, int option)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	int			a_len;

	a_len = ac - (1 + option);
	stack_a = NULL;
	if (init_stack_a(&stack_a, av + 1 + option, a_len) == ERROR)
		return (ERROR);
	stack_b = stacklst_nil();
	if (!stack_b)
		clear_exit(&stack_a, NULL, NULL, false);
	init_t_info(info, a_len - 1, &stack_a, &stack_b);
	return (SUCCESS);
}
