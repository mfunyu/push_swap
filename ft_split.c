/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 22:44:28 by mfunyu            #+#    #+#             */
/*   Updated: 2021/04/09 11:33:26 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_all(char **new, int i)
{
	while (i-- >= 0)
	{
		free(new[i]);
	}
	free(new);
}

static int	count_str(char const *s, char c)
{
	int		flag;
	int		cnt;

	flag = 0;
	cnt = 0;
	while (*s)
	{
		if (!flag && *s != c)
		{
			flag = 1;
			cnt++;
		}
		else if (*s++ == c)
			flag = 0;
	}
	return (cnt);
}

static char	**create_strs(char **new, const char *s, int cnt, char c)
{
	int		i;
	int		size;

	i = 0;
	while (i < cnt)
	{
		size = 0;
		while (*s == c)
			s++;
		while (*s && *s != c)
		{
			size++;
			s++;
		}
		new[i] = (char *)malloc((size + 1) * sizeof(char));
		if (!new[i])
		{
			free_all(new, i);
			return (NULL);
		}
		ft_strlcpy(new[i++], s++ - size, size + 1);
	}
	new[i] = NULL;
	return (new);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	int		cnt;

	if (!s)
		return (NULL);
	cnt = count_str(s, c);
	new = (char **)malloc((cnt + 1) * sizeof(char *));
	if (!new)
		return (NULL);
	create_strs(new, s, cnt, c);
	if (!new)
		return (NULL);
	return (new);
}
