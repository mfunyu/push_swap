/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 16:13:32 by mfunyu            #+#    #+#             */
/*   Updated: 2020/07/01 13:45:57 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		d_len;

	d_len = ft_strlen(dst);
	if (size <= d_len)
		return (size + ft_strlen(src));
	ft_strlcpy(dst + d_len, src, size - d_len);
	return (d_len + ft_strlen(src));
}

size_t	ft_strlen(const char *str)
{
	size_t len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}


void	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned long	i;

	i = 0;
	if (!dst)
		return ;
	if (size != 0)
	{
		while (i < size - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s - c == 0)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}
