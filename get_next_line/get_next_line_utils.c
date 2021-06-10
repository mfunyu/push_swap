/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 16:13:32 by mfunyu            #+#    #+#             */
/*   Updated: 2021/04/10 13:51:04 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strldup_check(char *s, int len, int *error)
{
	char	*dup;
	int		i;

	if (*error)
		return (NULL);
	i = 0;
	dup = (char *)malloc((len + 1) * sizeof(char));
	if (!dup)
	{
		*error = 1;
		return (NULL);
	}
	while (i < len && s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strldup(char *s, int len)
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

int	newline_index(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}
