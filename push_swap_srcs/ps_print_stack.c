#include "push_swap.h"

static void	print_title(t_op_name operation, char *str, t_options flag)
{
	int		len;
	int		i;

	if (flag == DISPLAY)
		ft_putstr_fd("<<", 1);
	else
		ft_putstr_fd("\e[36m<<", 1);
	len = 9;
	if (operation >= 8)
		len--;
	if (str)
		len = 11 - ft_strlen(str);
	i = 0;
	if (str)
		ft_putstr_fd(str, 1);
	else
		print_operation(operation, false);
	ft_putstr_fd(">> ", 1);
	while (i++ <= len)
		ft_putchar_fd('=', 1);
	ft_putstr_fd("_a_==========  ", 1);
	if (flag == DISPLAY)
		ft_putendl_fd(" ============_b_===========\n", 1);
	else
		ft_putstr_fd(" ============_b_===========\e[00m\n", 1);
}

void	print_format(char *order, char *elem, int b)
{
	int		len;

	ft_putstr_fd(" [ (", 1);
	ft_putstr_fd(order, 1);
	ft_putstr_fd(") ", 1);
	len = 22 - ft_strlen(elem) - ft_strlen(order);
	while (len--)
		ft_putchar_fd(' ', 1);
	ft_putstr_fd(elem, 1);
	if (b)
		ft_putendl_fd("]", 1);
	else
		ft_putstr_fd("]", 1);
	free(order);
	free(elem);
}

void	print_format_a(int index, char *order, char *elem, int max)
{
	int		i;

	i = 0;
	ft_putnbr_fd(index, STDOUT_FILENO);
	while (max / 10 > 0)
	{
		max /= 10;
		if (index / 10 > 0)
			index /= 10;
		else
			i++;
	}
	while (i--)
		ft_putchar_fd(' ', STDOUT_FILENO);
	ft_putstr_fd(":", STDOUT_FILENO);
	if (order)
		print_format(order, elem, 0);
	else
		ft_putstr_fd("                             ", STDOUT_FILENO);
}

void	ps_print_line(t_stack *lst_a, t_stack *lst_b)
{
	int		i;
	int		max;

	i = 0;
	max = stack_count(lst_a);
	while (!lst_a->nil || (lst_b && !lst_b->nil))
	{
		if (!lst_a->nil)
		{
			print_format_a(i, ft_itoa(lst_a->order), ft_itoa(lst_a->elem), max);
			lst_a = lst_a->next;
		}
		else
			print_format_a(i, NULL, NULL, max);
		if (lst_b && !lst_b->nil)
		{
			print_format(ft_itoa(lst_b->order), ft_itoa(lst_b->elem), 1);
			lst_b = lst_b->next;
		}
		else
			ft_putendl_fd("", 1);
		i++;
	}
}

void	sleep_and_clear(void)
{
	int			i;
	long long	sleep_seconds;

	sleep_seconds = 2000000;
	i = 0;
	while (i < sleep_seconds)
	{
		ft_putstr_fd("", 2);
		i++;
	}
	ft_putstr_fd(CLEAR_SCREEN, 1);
}

void	ps_print_stack(t_info *info, char *title, t_op_name name, t_options option)
{
	static t_options	flag;
	char				tmp;

	if (option != DISABLED)
		flag = option;
	if (flag == DISABLED)
		return ;
	if (flag != DISPLAY)
	{
		ps_print_line_insize(info->stack_a, info->stack_b);
	}
	else
		ps_print_line(info->stack_a, info->stack_b);
	print_title(name, title, flag);
	if (flag == AUTO)
		sleep_and_clear();
	if (flag == CONTROL)
		read(0, &tmp, 1);
}
