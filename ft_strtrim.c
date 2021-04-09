/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 21:21:51 by mfunyu            #+#    #+#             */
/*   Updated: 2021/04/09 11:34:21 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_tail(char const *s1, char const *set)
{
	int		tail;

	tail = ft_strlen(s1) - 1;
	while (tail >= 0)
	{
		if (!ft_strchr(set, s1[tail]))
			break ;
		tail--;
	}
	return (tail);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	int		tail;
	int		head;
	int		size;

	head = 0;
	if (!s1)
		return (NULL);
	tail = find_tail(s1, set);
	while (head < tail)
	{
		if (!ft_strchr(set, s1[head]))
			break ;
		head++;
	}
	size = tail - head + 1;
	trimmed = (char *)malloc((size + 1) * sizeof(char));
	if (!trimmed)
		return (NULL);
	ft_strlcpy(trimmed, s1 + head, size + 1);
	return (trimmed);
}
