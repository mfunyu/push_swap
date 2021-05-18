/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacklst_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 09:31:20 by mfunyu            #+#    #+#             */
/*   Updated: 2021/05/17 03:01:41 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stacklst_init(t_stack **head, int elem)
{
	t_stack		*new;

	if (!*head)
	{
		*head = stacklst_new(elem);
		if (!(*head))
			exit(EXIT_FAILURE);
	}
	else
	{
		new = stacklst_new(elem);
		if (!new)
			exit(EXIT_FAILURE);
		stacklst_add_back(head, new);
	}
}
