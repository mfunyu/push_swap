/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: u_2 <u_2@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 16:13:32 by mfunyu            #+#    #+#             */
/*   Updated: 2020/07/04 19:10:33 by u_2              ###   ########.fr       */
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
// ft_strlen(s) == len
char	*ft_strldup(const char *s, int len)
{
	char	*dup;

	dup = (char *)malloc((len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, s, len + 1);
	return (dup);
}

char	*ft_strljoin(char *s1, char *s2, int len)
{
	char			*joined;
	unsigned int	size;
	unsigned int	i;

    i = 0;
	if (!s2)
		return (NULL);
	size = len;
	if (*s1)
		size += ft_strlen(s1);
	joined = (char *)malloc((size + 1) * sizeof(char));
	if (!joined)
		return (NULL);
	while (*s1)
	{
		joined[i++] = *s1++;
	}
	while (len--)
	{
		joined[i++] = *s2++;
	}
	joined[i] = '\0';
	// free(s1);
	// free(s2);
	return (joined);
}


void	*ft_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned char	*new;

	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	new = malloc(nmemb * size);
	if (!new)
		return (NULL);
	ft_memset(new, '\0', nmemb * size);
	return (new);
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
