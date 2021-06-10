/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 15:26:59 by mfunyu            #+#    #+#             */
/*   Updated: 2020/07/01 11:49:32 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	l_size;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	if (len != 0)
	{
		l_size = ft_strlen(little);
		while (i < len - (l_size - 1) && big[i])
		{
			if (!ft_strncmp(big + i, little, l_size))
			{
				return ((char *)big + i);
			}
			i++;
		}
	}
	return (NULL);
}
