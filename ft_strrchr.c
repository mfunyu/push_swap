/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 17:53:28 by mfunyu            #+#    #+#             */
/*   Updated: 2020/06/30 15:31:24 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		index;

	index = ft_strlen(s) - 1;
	if (c == '\0')
		return ((char *)s + index + 1);
	while (index >= 0)
	{
		if (s[index] == c)
			return ((char *)s + index);
		index--;
	}
	return (NULL);
}
