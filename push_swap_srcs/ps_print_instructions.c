#include "push_swap.h"

void	print_operation(t_op_name name, bool newline)
{
	if (name == sa)
		ft_putstr_fd("sa", 1);
	if (name == sb)
		ft_putstr_fd("sb", 1);
	if (name == ss)
		ft_putstr_fd("ss", 1);
	if (name == pa)
		ft_putstr_fd("pa", 1);
	if (name == pb)
		ft_putstr_fd("pb", 1);
	if (name == ra)
		ft_putstr_fd("ra", 1);
	if (name == rb)
		ft_putstr_fd("rb", 1);
	if (name == rr)
		ft_putstr_fd("rr", 1);
	if (name == rra)
		ft_putstr_fd("rra", 1);
	if (name == rrb)
		ft_putstr_fd("rrb", 1);
	if (name == rrr)
		ft_putstr_fd("rrr", 1);
	if (newline)
		ft_putstr_fd("\n", 1);
}

bool	check_is_unneccesary_sb(t_simple *now)
{
	t_simple	*head;
	int			i;

	i = 0;
	head = now;
	while (i < 2)
	{
		if (now->value != pa || now->next->value != ra)
			return (false);
		now = now->next->next;
		i++;
	}
	if (i == 2)
	{
		while (i--)
		{
			head->value = pa;
			head->next->next->value = ra;
			head = head->next;
		}
		return (true);
	}
	return (false);
}

bool	check_is_unneccesary_sort_three(t_simple *now)
{
	t_simple	*head;
	int			i;

	i = 0;
	head = now;
	while (i < 3)
	{
		if (now->value != pa || now->next->value != ra)
			return (false);
		now = now->next->next;
		i++;
	}
	if (i == 3)
	{
		while (i--)
		{
			head->value = pa;
			head->next->next->next->value = ra;
			head = head->next;
		}
		return (true);
	}
	return (false);
}

void	print_instructions(t_info *info)
{
	t_simple	*operation;

	operation = info->instructions;
	while (operation)
	{
		if (operation->value == sb && check_is_unneccesary_sb(operation->next))
		{
			operation = operation->next;
			continue ;
		}
		if (operation->value == sb && operation->next->value == rrb
			&& check_is_unneccesary_sort_three(operation->next->next))
		{
			operation = operation->next->next;
			continue ;
		}
		print_operation(operation->value, true);
		operation = operation->next;
	}
}
