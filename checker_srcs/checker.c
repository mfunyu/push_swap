#include "checker.h"

void	display_result(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a, stack_b))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_list	*instructions;
	int		option;
	int		ret;

	if (ac <= 1)
		return (SUCCESS);
	option = 0;
	if (!is_valid_arg(av, &option))
		return (ERROR);
	if (ch_init_stacks(&stack_a, &stack_b, av, option) == ERROR)
		return (clear_return(&stack_a, &stack_b));
	ch_print_stack(stack_a, NULL, "input", option);
	ret = read_instructions(&instructions);
	if (ret == FAILURE)
		clear_exit(&stack_a, &stack_b);
	if (ret == ERROR)
		return (clear_return(&stack_a, &stack_b));
	execute_instructions(&stack_a, &stack_b, instructions, option);
	display_result(stack_a, stack_b);
	clear_all(&stack_a, &stack_b, &instructions);
	return (SUCCESS);
}
