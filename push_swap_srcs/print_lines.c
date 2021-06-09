#include "push_swap.h"

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

void	print_a_line(t_stack *lst_a, t_stack *lst_b, int index, int max)
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

void	print_lines_fit(t_stack *lst_a, t_stack *lst_b, int stack_height, t_options flag)
{
	static int	max;
	t_stack		*last;
	int			len_a;
	int			i;

	len_a = stack_count(lst_a);
	if (!max)
		max = len_a;
	i = 0;
	last = lst_a->prev->prev;
	while ((!lst_a->nil || (lst_b && !lst_b->nil))
		&& (i < stack_height || flag == DISPLAYALL || len_a <= stack_height + 2))
	{
		print_a_line(lst_a, lst_b, i++, max);
		if (!lst_a->nil)
			lst_a = lst_a->next;
		if (lst_b && !lst_b->nil)
			lst_b = lst_b->next;
	}
	if (flag == DISPLAYALL || len_a <= stack_height + 2)
		return ;
	ft_putendl_fd("      (abbreviated)", STDOUT_FILENO);
	if (!lst_a->nil)
		print_format_a(len_a - 1, ft_itoa(last->order), ft_itoa(last->elem), max);
	ft_putendl_fd("", STDOUT_FILENO);
}

void	print_lines(t_stack *lst_a, t_stack *lst_b, t_options flag)
{
	static int	height;

	if (flag != DISPLAYALL)
		ft_putstr_fd(CLEAR_SCREEN, STDOUT_FILENO);
	if (flag != DISPLAYALL && !height)
		height = get_terminal_height() - 3;
	print_lines_fit(lst_a, lst_b, height - 1, flag);
}
