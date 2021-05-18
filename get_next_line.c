/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 18:32:49 by mfunyu            #+#    #+#             */
/*   Updated: 2021/05/17 02:32:01 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	null_free(char **buf, int ret)
{
	if (!buf)
		return (ret);
	free(*buf);
	*buf = NULL;
	return (ret);
}

static int	invaild(int fd)
{
	if (fd < 0 || fd == 1 || fd == 2 || fd > 255)
		return (1);
	return (0);
}

static int	newline_in_str(char **line, char **str, char **save, int *error)
{
	char	*new_save;
	int		index;

	index = newline_index(*str);
	if (index)
	{
		*line = ft_strljoin(*line, *str, index - 1);
		if (!*line)
			*error = 1;
		if (!*error && index != (int)ft_strlen(*str))
		{
			new_save = ft_strldup(*str + index, ft_strlen(*str + index));
			if (!new_save)
				*error = 1;
			return (null_free(save, 1));
		}
		return (null_free(save, 1));
	}
	*line = ft_strljoin(*line, *str, ft_strlen(*str) + 1);
	if (*line)
		*error = 1;
	return (null_free(save, 0));
}

int	get_next_line_return(int error, int bytes_red, char *buf, char **line)
{
	if (error || bytes_red < 0 || !buf)
		return (null_free(&buf, 0));
	if (!*line)
	{
		*line = ft_strldup("", 0);
		if (!*line)
			return (-1);
	}
	return (null_free(&buf, 0));
}

int	get_next_line(int fd, char **line)
{
	static char	*save;
	char		*buf;
	int			bytes_red;
	int			error;

	error = 0;
	if (!line || BUFFER_SIZE < 1 || invaild(fd))
		return (-1);
	*line = ft_strldup_check("", 0, &error);
	if (!error && save && newline_in_str(line, &save, &save, &error))
		return (1);
	if (error)
		return (-1);
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (buf && !error)
	{
		bytes_red = read(fd, buf, BUFFER_SIZE);
		if (bytes_red <= 0)
			break ;
		buf[bytes_red] = '\0';
		if (newline_in_str(line, &buf, &save, &error))
			return (null_free(&buf, 1));
	}
	return (get_next_line_return(error, bytes_red, buf, line));
}
