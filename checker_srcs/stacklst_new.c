/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacklst_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 09:39:02 by mfunyu            #+#    #+#             */
/*   Updated: 2021/05/18 14:15:34 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stack	*stacklst_new(int elem)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->elem = elem;
	new->prev = NULL;
	new->next = NULL;
	new->nil = 0;
	return (new);
}

t_stack	*stacklst_nil(void)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->elem = 0;
	new->prev = new;
	new->next = new;
	new->nil = 1;
	return (new);
}
