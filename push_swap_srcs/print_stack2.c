/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 10:16:24 by mfunyu            #+#    #+#             */
/*   Updated: 2021/05/21 00:37:44 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	print_stack2(t_info *info, char *title)
{
	t_stack		*lst_a;
	t_stack		*lst_b;
	int			i;

	i = 0;
	lst_a = info->stack_a;
	lst_b = info->stack_b;
	printf("\e[36m--------- %-7s ---------\e[00m\n", title);
	while (!lst_a->nil || (lst_b && !lst_b->nil))
	{
		if (!lst_a->nil)
		{
			printf("%d: [ (%d)%5d]", i, lst_a->order, lst_a->elem);
			lst_a = lst_a->next;
		}
		else
			printf("%d: %12s", i, "");
		if (lst_b && !lst_b->nil)
		{
			printf("[ (%d)%5d]\n", lst_b->order, lst_b->elem);
			lst_b = lst_b->next;
		}
		else
			printf("\n");
		i++;
	}
	return (0);
}
