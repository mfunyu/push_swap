#include "push_swap.h"

static void	print_title(t_op_name operation, char *str, t_options flag)
{
	int		len;
	int		i;

	if (flag != DISPLAYALL)
		ft_putstr_fd(C_CYAN, STDOUT_FILENO);
	ft_putstr_fd("<<", STDOUT_FILENO);
	len = STACK_WIDTH - 2;
	if (operation >= rra)
		len--;
	if (str)
		len = STACK_WIDTH - ft_strlen(str);
	if (str)
		ft_putstr_fd(str, STDOUT_FILENO);
	else
		print_operation(operation, false);
	ft_putstr_fd(">> ", STDOUT_FILENO);
	i = 0;
	while (i++ <= len)
		ft_putchar_fd('=', STDOUT_FILENO);
	ft_putstr_fd("_a_==========  ", STDOUT_FILENO);
	ft_putendl_fd(STR_STACK_B, STDOUT_FILENO);
	if (flag != DISPLAYALL)
		ft_putstr_fd(C_DEFAULT, STDOUT_FILENO);
}

void	print_stack(t_info *info, char *title, t_op_name name, t_options option)
{
	static t_options	flag;
	char				tmp;

	if (option != NORMAL)
		flag = option;
	if (flag == NORMAL)
		return ;
	print_lines(info->stack_a, info->stack_b, flag);
	print_title(name, title, flag);
	if (flag == DISPLAYALL)
		ft_putendl_fd("", STDOUT_FILENO);
	if (flag == AUTOPLAY)
		sleep_and_clear();
	if (flag == CONTROL)
		read(STDIN_FILENO, &tmp, 1);
}
