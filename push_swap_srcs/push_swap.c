#include "push_swap.h"

int	main(int ac, char **av)
{
	t_info		*info;
	t_options	option;
	int			flag;

	if (ac <= 1)
		return (false);
	option = NORMAL;
	if (!is_valid_arg(av, &option))
		return (SUCCESS);
	flag = 0;
	if (option)
		flag = 1;
	if (init_info(&info, av, ac, flag) == ERROR)
		return (SUCCESS);
	print_stack(info, "start", -1, option);
	sort_stack(&info, A);
	print_stack(info, "end", -1, NORMAL);
	print_instructions(info);
	clear_info(&info);
	return (SUCCESS);
}
