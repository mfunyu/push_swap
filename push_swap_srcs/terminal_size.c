#include "push_swap.h"

int	get_terminal_height(void)
{
	char	c;
	int		i;

	ft_putstr_fd("\x1b[999B", STDOUT_FILENO);
	ft_putendl_fd("Setting up the height: please press enter", STDOUT_FILENO);
	ft_putstr_fd("\x1b[6n", STDOUT_FILENO);
	i = 0;
	while (1)
	{
		read(STDIN_FILENO, &c, 1);
		if (ft_isdigit(c))
			i = i * 10 + (c - '0');
		if (c == ';')
			break ;
	}
	// ft_putstr_fd(CLEAR_SCREEN, 1);
	return (i);
}

void	ps_print_line_insize(t_stack *lst_a, t_stack *lst_b)
{
	static int	height;
	t_stack		*last;
	int			len_a;
	int			i;

	ft_putstr_fd(CLEAR_SCREEN, STDOUT_FILENO);
	last = lst_a->prev->prev;
	if (!height)
		height = get_terminal_height() - 4;
	len_a = stack_count(lst_a);
	if (height + 1 >= len_a)
	{
		ps_print_line(lst_a, lst_b);
		return ;
	}
	i = height;
	while (i && (!lst_a->nil || (lst_b && !lst_b->nil)))
	{
		if (!lst_a->nil)
		{
			print_format_a(height - i, ft_itoa(lst_a->order), ft_itoa(lst_a->elem), len_a);
			lst_a = lst_a->next;
		}
		else
			print_format_a(i, NULL, NULL, len_a);
		if (lst_b && !lst_b->nil)
		{
			print_format(ft_itoa(lst_b->order), ft_itoa(lst_b->elem), 1);
			lst_b = lst_b->next;
		}
		else
			ft_putendl_fd("", STDOUT_FILENO);
		i--;
	}
	printf("      (abbribiaated)    \n");
	if (!lst_a->nil)
		print_format_a(len_a, ft_itoa(last->order), ft_itoa(last->elem), len_a);
	ft_putendl_fd("", STDOUT_FILENO);
}
