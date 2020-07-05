/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 16:13:32 by mfunyu            #+#    #+#             */
/*   Updated: 2020/07/05 09:12:39 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strldup(char *s, int len, int need_free)
{
	char	*dup;
	int		i;

	i = 0;
	dup = (char *)malloc((len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	while (i < len && s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	if (need_free)
		free(s);
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
	while (s1[i])
	{
		joined[i] = s1[i];
		i++;
	}
	while (len--)
	{
		joined[i++] = *s2++;
	}
	free(s1);
	joined[i] = '\0';
	return (joined);
}

void	*ft_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned char	*new;
	unsigned int	i;

	i = 0;
	new = malloc(nmemb * size);
	if (!new)
		return (NULL);
	while (i < nmemb * size)
	{
		new[i] = '\0';
		i++;
	}
	return (new);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
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
