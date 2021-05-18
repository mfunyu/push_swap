/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacklst_add_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 15:49:42 by mfunyu            #+#    #+#             */
/*   Updated: 2021/05/18 13:07:11 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	stacklst_add_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		last = stacklst_last(*lst);
		last->next = new;
		new->prev = last;
		// stacklst_insert((*lst)->prev->prev, (*lst)->prev, new);
	}
}
