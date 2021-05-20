/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:25:56 by mfunyu            #+#    #+#             */
/*   Updated: 2021/05/20 14:36:39 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

// void	end(void)__attribute__((destructor));

// void	end(void)
// {
// 	system("leaks checker");
// }

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_list	*instructions;

	if (!is_valid_arg(ac, av))
		return (0);
	if (ch_init_stacks(&stack_a, &stack_b, av) == ERROR)
		return (0);
	print_stack(stack_a, NULL, "initial");
	if (read_instructions(&stack_a, &instructions) == ERROR)
		return (0);
	if (execute_instructions(&stack_a, &stack_b, instructions) == ERROR)
		return (0);
	if (is_sorted(stack_a, stack_b))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	ft_lstclear(&instructions, free);
	stacklst_clear(&stack_a);
	stacklst_clear(&stack_b);
	return (0);
}
