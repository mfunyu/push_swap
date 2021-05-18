/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacklst_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 15:49:42 by mfunyu            #+#    #+#             */
/*   Updated: 2021/05/18 17:23:17 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	stacklst_clear(t_stack **lst)
{
	t_stack	*next;

	(*lst)->prev->next = NULL;
	while (*lst)
	{
		next = (*lst)->next;
		null_free((char **)(lst));
		*lst = next;
	}
	lst = NULL;
}
