/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:25:56 by mfunyu            #+#    #+#             */
/*   Updated: 2021/05/18 18:47:52 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

// void	end(void)__attribute__((destructor));

// void	end(void)
// {
// 	system("leaks checker");
// }

bool	is_valid_arg(int ac, char **av)
{
	int		error;
	int		i;

	if (ac <= 1)
		return (false);
	i = 0;
	while (av[++i] && !error)
		ft_atoi_check(av[i], &error);
	if (error)
	{
		ft_putendl_fd("Error", 2);
		return (false);
	}
	return (true);
}

int	check_dup_add_back(t_stack **stack_a, t_stack *new)
{
	t_stack		*node;

	if (*stack_a == NULL)
		*stack_a = new;
	else
	{
		node = *stack_a;
		while (1)
		{
			if (node->elem == new->elem)
			{
				stacklst_clear(stack_a);
				stacklst_clear(&new);
				ft_putendl_fd("Error", 2);
				return (ERROR);
			}
			if (!node->next)
				break ;
			node = node->next;
		}
		node->next = new;
		new->prev = node;
	}
	return (SUCCESS);
}

int	init_stack_a(t_stack **stack_a, char **av)
{
	t_stack		*new;
	t_stack		*nil;
	int			i;

	*stack_a = NULL;
	i = 0;
	while (av[++i])
	{
		new = stacklst_new(ft_atoi(av[i]));
		if (!new)
			exit(EXIT_FAILURE);
		if (check_dup_add_back(stack_a, new) == ERROR)
			return (ERROR);
	}
	nil = stacklst_nil();
	stacklst_add_back(stack_a, nil);
	stacklst_add_front(stack_a, nil);
	return (SUCCESS);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_list	*instructions;

	if (!is_valid_arg(ac, av))
		return (0);
	if (init_stack_a(&stack_a, av) == ERROR)
		return (0);
	print_stack(stack_a, NULL, "initial");
	if (read_instructions(&stack_a, &instructions) == ERROR)
		return (0);
	if (execute_instructions(&stack_a, instructions) == ERROR)
		return (0);
	return (0);
}
