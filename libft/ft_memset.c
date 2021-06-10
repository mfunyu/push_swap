/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 13:36:17 by mfunyu            #+#    #+#             */
/*   Updated: 2020/06/30 14:52:32 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, unsigned int n)
{
	unsigned int	i;
	unsigned char	*s_copy;

	i = 0;
	s_copy = (unsigned char *)s;
	while (i < n)
	{
		s_copy[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
