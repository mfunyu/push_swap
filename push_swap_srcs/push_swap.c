#include "push_swap.h"

int	main(int ac, char **av)
{
	t_info	*info;
	int		option;

	if (ac <= 1)
		return (false);
	option = 0;
	if (!is_valid_arg(av, &option))
		return (0);
	if (ps_init_info(&info, av, ac, option) == ERROR)
		return (0);
	ps_print_stack(info, "start", option);
	sort_stack(&info, A);
	ps_print_stack(info, "end", 0);
	print_instructions(info);
	clear_info(&info);
	return (0);
}
