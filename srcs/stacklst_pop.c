/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacklst_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 09:39:02 by mfunyu            #+#    #+#             */
/*   Updated: 2021/05/19 00:45:39 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_stack	*stacklst_pop(t_stack **lst, bool head)
{
	t_stack		*pop;

	if (head)
	{
		pop = *lst;
		*lst = pop->next;
	}
	else
		pop = (*lst)->prev->prev;
	pop->prev->next = pop->next;
	pop->next->prev = pop->prev;
	return (pop);
}
