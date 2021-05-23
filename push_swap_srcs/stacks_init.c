#include "push_swap.h"

int	init_stack_a(t_stack **stack_a, char **av, int a_len)
{
	t_stack		*sorted_stack;

	sorted_stack = get_order(av, a_len);
	if (check_av_dup(sorted_stack) == ERROR)
		return (ERROR);
	*stack_a = stacklst_nil();
	if (!*stack_a)
	{
		null_free((void **)&sorted_stack);
		exit(EXIT_FAILURE);
	}
	init_stacklst_a(stack_a, sorted_stack, av, a_len);
	return (SUCCESS);
}

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
	(*info)->a_pivot = -1;
	(*info)->a_len = a_index;
	(*info)->sorted_id = -1;
	(*info)->stack_a = *stack_a;
	(*info)->stack_b = *stack_b;
	(*info)->instructions = NULL;
	(*info)->pivot = NULL;
}

int	ps_init_info(t_info **info, char **av, int ac, int option)
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
