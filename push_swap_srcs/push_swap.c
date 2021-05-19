/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:58:34 by mfunyu            #+#    #+#             */
/*   Updated: 2021/05/19 12:51:19 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	end(void)__attribute__((destructor));

void	end(void)
{
	system("leaks push_swap");
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_list	*instructions;

	if (!is_valid_arg(ac, av))
		return (0);
	if (init_stacks(&stack_a, &stack_b, av) == ERROR)
		return (0);
	print_stack(stack_a, stack_b, "start");
	sort_stack(&stack_a, &stack_b, &instructions);
	print_stack(stack_a, stack_b, "end");
	print_instructions(instructions);
	ft_lstclear(&instructions, free);
	stacklst_clear(&stack_a);
	stacklst_clear(&stack_b);
	return (0);
}
