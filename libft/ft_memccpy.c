/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 16:12:48 by mfunyu            #+#    #+#             */
/*   Updated: 2020/06/30 17:54:13 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int ch, size_t n)
{
	unsigned char	*d_copy;
	unsigned char	*s_copy;

	d_copy = (unsigned char *)dst;
	s_copy = (unsigned char *)src;
	if (ft_memchr(s_copy, ch, n))
	{
		while (n)
		{
			*d_copy++ = *s_copy;
			if (*s_copy++ == (unsigned char)ch)
				return (d_copy);
			n--;
		}
	}
	ft_memcpy(d_copy, s_copy, n);
	return (NULL);
}
