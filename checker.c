/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:25:56 by mfunyu            #+#    #+#             */
/*   Updated: 2021/04/10 09:12:15 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	int		i;
	int		error;

	if (ac <= 1)
		return (0);
	i = 1;
	while (av[i])
	{
		ft_atoi_check(av[i], &error);
		if (error)
		{
			ft_putendl_fd("Error", 1);
			return (0);
		}
		i++;

	}
	return (0);
}
