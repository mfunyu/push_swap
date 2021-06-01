#include "push_swap.h"

int	main(int ac, char **av)
{
	t_info		*info;
	t_options	option;
	int			flag;

	if (ac <= 1)
		return (false);
	option = DISABLED;
	if (!is_valid_arg(av, &option))
		return (0);
	flag = 0;
	if (option)
		flag = 1;
	if (ps_init_info(&info, av, ac, flag) == ERROR)
		return (0);
	ps_print_stack(info, "start", -1, option);
	sort_stack(&info, A);
	ps_print_stack(info, "end", -1, 0);
	print_instructions(info);
	clear_info(&info);
	return (0);
}
