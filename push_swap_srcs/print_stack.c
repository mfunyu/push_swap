#include "push_swap.h"

static void	print_title(t_op_name operation, char *str, t_options flag)
{
	int		len;
	int		i;

	if (flag != DISPLAY)
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
	if (flag != DISPLAY)
		ft_putstr_fd(C_DEFAULT, STDOUT_FILENO);
}

void	print_format(char *order, char *elem, bool is_stack_b)
{
	int		len;

	ft_putstr_fd(" [ (", STDOUT_FILENO);
	ft_putstr_fd(order, STDOUT_FILENO);
	ft_putstr_fd(") ", STDOUT_FILENO);
	len = STACK_WIDTH * 2 - ft_strlen(elem) - ft_strlen(order);
	while (len--)
		ft_putchar_fd(' ', STDOUT_FILENO);
	ft_putstr_fd(elem, STDOUT_FILENO);
	ft_putstr_fd("]", STDOUT_FILENO);
	if (is_stack_b)
		ft_putendl_fd("", STDOUT_FILENO);
	free(order);
	free(elem);
}

void	print_format_a(int index, char *order, char *elem, int len_a)
{
	int			i;

	i = 0;
	ft_putnbr_fd(index, STDOUT_FILENO);
	while (len_a / 10 > 0)
	{
		len_a /= 10;
		if (index / 10 > 0)
			index /= 10;
		else
			i++;
	}
	while (i--)
		ft_putchar_fd(' ', STDOUT_FILENO);
	ft_putstr_fd(":", STDOUT_FILENO);
	if (order)
		print_format(order, elem, false);
	else
		ft_putstr_fd(STR_EMPTY_A, STDOUT_FILENO);
}

void	ps_print_a_line(t_stack *lst_a, t_stack *lst_b, int index, int max)
{
	if (!lst_a->nil)
		print_format_a(index, ft_itoa(lst_a->order), ft_itoa(lst_a->elem), max);
	else
		print_format_a(index, NULL, NULL, max);
	if (lst_b && !lst_b->nil)
		print_format(ft_itoa(lst_b->order), ft_itoa(lst_b->elem), true);
	else
		ft_putendl_fd("", STDOUT_FILENO);
}

void	print_lines_fit(t_stack *lst_a, t_stack *lst_b, int height, int max)
{
	t_stack	*last;
	int		len_a;
	int		i;

	i = 0;
	len_a = stack_count(lst_a);
	last = lst_a->prev->prev;
	while (i < height && (!lst_a->nil || (lst_b && !lst_b->nil)))
	{
		ps_print_a_line(lst_a, lst_b, i, max);
		if (!lst_a->nil)
			lst_a = lst_a->next;
		if (lst_b && !lst_b->nil)
			lst_b = lst_b->next;
		i++;
	}
	ft_putendl_fd("      (abbreviated)", STDOUT_FILENO);
	if (!lst_a->nil)
		print_format_a(len_a, ft_itoa(last->order), ft_itoa(last->elem), max);
	ft_putendl_fd("", STDOUT_FILENO);
}

void	print_lines(t_stack *lst_a, t_stack *lst_b, t_options flag)
{
	static int	height;
	static int	max;
	int			len_a;
	int			i;

	ft_putstr_fd(CLEAR_SCREEN, STDOUT_FILENO);
	if (!max)
		max = stack_count(lst_a);
	if (!height)
		height = get_terminal_height() - 3;
	len_a = stack_count(lst_a);
	if (flag == DISPLAY || height >= len_a)
	{
		i = 0;
		while (!lst_a->nil || (lst_b && !lst_b->nil))
		{
			ps_print_a_line(lst_a, lst_b, i++, max);
			if (!lst_a->nil)
				lst_a = lst_a->next;
			if (lst_b && !lst_b->nil)
				lst_b = lst_b->next;
		}
		return ;
	}
	print_lines_fit(lst_a, lst_b, height - 1, max);
}

void	print_stack(t_info *info, char *title, t_op_name name, t_options option)
{
	static t_options	flag;
	char				tmp;

	if (option != DISABLED)
		flag = option;
	if (flag == DISABLED)
		return ;
	print_lines(info->stack_a, info->stack_b, flag);
	print_title(name, title, flag);
	if (flag == AUTO)
		sleep_and_clear();
	if (flag == CONTROL)
		read(0, &tmp, 1);
}
