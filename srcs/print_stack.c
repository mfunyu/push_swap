/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 10:16:24 by mfunyu            #+#    #+#             */
/*   Updated: 2021/05/20 14:25:23 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
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
