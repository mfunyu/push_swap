/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacklst_insert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 09:39:02 by mfunyu            #+#    #+#             */
/*   Updated: 2021/05/22 20:04:17 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	stacklst_insert(t_stack *first, t_stack *second, t_stack *insert)
{
	first->next = insert;
	second->prev = insert;
	insert->prev = first;
	insert->next = second;
}
