/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:58:34 by mfunyu            #+#    #+#             */
/*   Updated: 2021/05/21 21:32:54 by mfunyu           ###   ########.fr       */
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
	int		option;

	option = 0;
	if (!is_valid_arg(ac, av, &option))
		return (0);
	if (ps_init_info(&info, av, ac, option) == ERROR)
		return (0);
	ps_print_stack(info, "start", option);
	sort_stack(&info, A);
	ps_print_stack(info, "end", 0);
	print_instructions(info);
	clear_info(&info);
	return (0);
}
