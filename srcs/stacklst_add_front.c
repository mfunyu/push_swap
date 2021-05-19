/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacklst_add_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 15:49:42 by mfunyu            #+#    #+#             */
/*   Updated: 2021/05/19 00:46:32 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	stacklst_add_front(t_stack **lst, t_stack *new)
{
	// t_stack		*save;

	// save = *lst;
	new->next = *lst;
	(*lst)->prev = new;
	// stacklst_insert((*lst)->prev, *lst, new);
	// *lst = new;
}
