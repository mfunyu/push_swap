/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 10:36:19 by mfunyu            #+#    #+#             */
/*   Updated: 2020/06/30 17:13:07 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*head;
	t_list	*prev;

	prev = NULL;
	while (lst)
	{
		new = ft_lstnew(f(lst->content));
		if (!prev)
		{
			head = new;
		}
		else
		{
			prev->next = new;
		}
		if (!new)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		lst = lst->next;
		prev = new;
	}
	return (head);
}
