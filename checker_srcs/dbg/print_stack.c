/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 10:16:24 by mfunyu            #+#    #+#             */
/*   Updated: 2021/05/18 14:46:12 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

int	print_stack(t_stack *lst_a, t_stack *lst_b, char *title)
{
	int			i;

	i = 0;
	printf("\e[36m--------- %-7s ---------\e[00m\n", title);
	while (!lst_a->nil || (lst_b && !lst_b->nil))
	{
		if (!lst_a->nil)
		{
			printf("%d: [%10d]", i, lst_a->elem);
			lst_a = lst_a->next;
		}
		else
			printf("%d: %12s", i, "");
		if (lst_b && !lst_b->nil)
		{
			printf("[%10d]\n", lst_b->elem);
			lst_b = lst_b->next;
		}
		else
			printf("\n");
		i++;
	}
	return (0);
}
