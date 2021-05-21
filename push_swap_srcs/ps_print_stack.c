/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_print_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 10:16:24 by mfunyu            #+#    #+#             */
/*   Updated: 2021/05/21 18:29:29 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static void	print_format_a(int i, char *order, char *elem)
{
	int		len;

	ft_putnbr_fd(i, 1);
	ft_putstr_fd(": [", 1);
	if (order)
	{
		ft_putstr_fd(" (", 1);
		ft_putstr_fd(order, 1);
		ft_putstr_fd(") ", 1);
	}
	else
	{
		len = 20 - ft_strlen(elem);
		while (len--)
			ft_putchar_fd(' ', 1);
	}
	ft_putstr_fd(elem, 1);
	ft_putstr_fd("]", 1);
}

static void	print_format_b(int order, int elem)
{
	int		len;

	ft_putstr_fd("[", 1);
	ft_putstr_fd(" (", 1);
	ft_putnbr_fd(order, 1);
	ft_putstr_fd(") ", 1);
	len = 10 - ft_strlen(ft_itoa(elem));
	while (len--)
		ft_putchar_fd(' ', 1);
	ft_putnbr_fd(elem, 1);
	ft_putendl_fd("]", 1);
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
			print_format_a(i, NULL, " ");
		if (lst_b && !lst_b->nil)
		{
			print_format_b(lst_b->order, lst_b->elem);
			lst_b = lst_b->next;
		}
		else
			ft_putendl_fd("", 1);
		i++;
	}
}
