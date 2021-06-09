#include "checker.h"

void	display_result(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a, stack_b))
		ft_putendl_fd("OK", STDOUT_FILENO);
	else
		ft_putendl_fd("KO", STDOUT_FILENO);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_list	*instructions;
	int		ret;

	if (ac <= 1)
		return (SUCCESS);
	if (!is_valid_arg(av, NULL))
		return (SUCCESS);
	if (ch_init_stacks(&stack_a, &stack_b, av) == ERROR)
		return (clear_return(&stack_a, &stack_b));
	ret = read_instructions(&instructions);
	if (ret == FAILURE)
		clear_exit(&stack_a, &stack_b);
	if (ret == ERROR)
		return (clear_return(&stack_a, &stack_b));
	execute_instructions(&stack_a, &stack_b, instructions);
	display_result(stack_a, stack_b);
	clear_all(&stack_a, &stack_b, &instructions);
	return (SUCCESS);
}
