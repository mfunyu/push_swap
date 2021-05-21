/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:58:34 by mfunyu            #+#    #+#             */
/*   Updated: 2021/05/21 16:21:37 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	end(void)__attribute__((destructor));

// void	end(void)
// {
// 	system("leaks push_swap");
// }

int	main(int ac, char **av)
{
	t_info	*info;

	if (!is_valid_arg(ac, av))
		return (0);
	if (ps_init_info(&info, av, ac) == ERROR)
		return (0);
	// ps_print_stack(info, "start");
	sort_stack(&info, A);
	// ps_print_stack(info, "end");
	print_instructions(info);
	// clear_info(&info);
	return (0);
}
