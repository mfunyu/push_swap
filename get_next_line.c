/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 18:32:49 by mfunyu            #+#    #+#             */
/*   Updated: 2020/07/06 17:52:08 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int		invaild(int fd)
{
	if (fd < 0 || fd == 1 || fd == 2 || fd > 255)
		return (1);
	return (0);
}

static int		newline_index(char *s)
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

static int		newline_in_str(char **line, char **str, char **save, int *error)
{
	char	*new_save;
	int		index;

	index = 0;
	if (!*error && (index = newline_index(*str)))
	{
		if (!(*line = ft_strljoin(*line, *str, index - 1)))
			*error = 1;
		if (!*error && index != (int)ft_strlen(*str))
		{
			if (!(new_save = ft_strldup(*str + index, ft_strlen(*str + index))))
				*error = 1;
			free(*save);
			*save = new_save;
			return (1);
		}
		free(*save);
		*save = NULL;
		return (1);
	}
	if (!*error && !(*line = ft_strljoin(*line, *str, ft_strlen(*str) + 1)))
		*error = 1;
	free(*save);
	*save = NULL;
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static char	*save;
	char		*buf;
	int			bytes_red;
	int			error;

	error = 0;
	if (!line || !(*line = ft_strldup("", 0)) || BUFFER_SIZE < 1 || invaild(fd))
		return (-1);
	if (save && newline_in_str(line, &save, &save, &error))
		return (1);
	if (!error && !(buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return (-1);
	while (!error && (bytes_red = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[bytes_red] = '\0';
		if (newline_in_str(line, &buf, &save, &error))
		{
			free(buf);
			return (1);
		}
	}
	free(buf);
	if (error || bytes_red < 0 || (!*line && !(*line = ft_strldup("", 0))))
		return (-1);
	return (0);
}
