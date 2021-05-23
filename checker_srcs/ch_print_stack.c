#include "checker.h"

static void	print_title(char *str)
{
	int		len;
	int		i;

	ft_putstr_fd("\e[36m----------", 1);
	len = 10 - ft_strlen(str);
	i = 0;
	while (i++ < len / 2)
		ft_putchar_fd(' ', 1);
	ft_putstr_fd(str, 1);
	while (i++ <= len)
		ft_putchar_fd(' ', 1);
	ft_putstr_fd("----------\e[00m\n", 1);
}

static void	print_format(char *elem, int b)
{
	int		len;

	ft_putstr_fd(" [", 1);
	len = 11 - ft_strlen(elem);
	while (len--)
		ft_putchar_fd(' ', 1);
	ft_putstr_fd(elem, 1);
	if (b)
		ft_putendl_fd("]", 1);
	else
		ft_putstr_fd("]", 1);
	free(elem);
}

static void	print_format_a(int i, char *elem)
{
	ft_putnbr_fd(i, 1);
	ft_putstr_fd(":", 1);
	if (elem)
		print_format(elem, 0);
	else
		ft_putstr_fd("             ", 1);
}

void	ch_print_stack(t_stack *lst_a, t_stack *lst_b, char *title, int option)
{
	int			i;

	if (!option)
		return ;
	i = 0;
	print_title(title);
	while (!lst_a->nil || (lst_b && !lst_b->nil))
	{
		if (!lst_a->nil)
		{
			print_format_a(i, ft_itoa(lst_a->elem));
			lst_a = lst_a->next;
		}
		else
			print_format_a(i, NULL);
		if (lst_b && !lst_b->nil)
		{
			print_format(ft_itoa(lst_b->elem), 1);
			lst_b = lst_b->next;
		}
		else
			ft_putendl_fd("", 1);
		i++;
	}
}
