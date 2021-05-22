#include "push_swap.h"

static void	print_title(char *str)
{
	int		len;
	int		i;

	ft_putstr_fd("\e[36m---------", 1);
	len = 9 - ft_strlen(str);
	i = 0;
	while (i++ < len / 2)
		ft_putchar_fd(' ', 1);
	ft_putstr_fd(str, 1);
	while (i++ <= len)
		ft_putchar_fd(' ', 1);
	ft_putstr_fd("---------\e[00m\n", 1);
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

void	ps_print_stack(t_info *info, char *title, int option)
{
	t_stack		*lst_a;
	t_stack		*lst_b;
	static int	flag;
	int			i;

	if (option == 1)
		flag = option;
	if (!flag)
		return ;
	i = 0;
	lst_a = info->stack_a;
	lst_b = info->stack_b;
	print_title(title);
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
