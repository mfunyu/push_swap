/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacklst_insert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 09:39:02 by mfunyu            #+#    #+#             */
/*   Updated: 2021/05/18 12:44:51 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	stacklst_insert(t_stack *a, t_stack *b, t_stack *new)
{
	a->next = new;
	b->prev = new;
	new->prev = a;
	new->next = b;
}
