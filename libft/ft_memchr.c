/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 16:12:57 by mfunyu            #+#    #+#             */
/*   Updated: 2020/06/30 14:48:53 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *buf, int ch, size_t n)
{
	unsigned char	*b_copy;

	b_copy = (unsigned char *)buf;
	while (n)
	{
		if (*b_copy == (unsigned char)ch)
			return ((void *)b_copy);
		b_copy++;
		n--;
	}
	return (NULL);
}
