#include "push_swap.h"

static void	print_title(t_op_name operation, char *str)
{
	int		len;
	int		i;

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
	ft_putstr_fd(" ============_b_===========\e[00m\n", 1);
}

static void	print_format(char *order, char *elem, int b)
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

static void	print_format_a(int i, char *order, char *elem)
{
	ft_putnbr_fd(i, 1);
	ft_putstr_fd(":", 1);
	if (order)
		print_format(order, elem, 0);
	else
		ft_putstr_fd("                             ", 1);
}

void	ps_print_line(t_stack *lst_a, t_stack *lst_b)
{
	int		i;

	i = 0;
	while (!lst_a->nil || (lst_b && !lst_b->nil))
	{
		if (!lst_a->nil)
		{
			print_format_a(i, ft_itoa(lst_a->order), ft_itoa(lst_a->elem));
			lst_a = lst_a->next;
		}
		else
			print_format_a(i, NULL, NULL);
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

void	ps_print_stack(t_info *info, char *title, t_op_name name, int option)
{
	static int	flag;

	if (option == 1)
		flag = option;
	if (!flag)
		return ;
	print_title(name, title);
	ps_print_line(info->stack_a, info->stack_b);
	ft_putstr_fd("\n", 1);
}
