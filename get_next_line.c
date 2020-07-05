/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 18:32:49 by mfunyu            #+#    #+#             */
/*   Updated: 2020/07/05 20:02:36 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		newline_in_str(char **line, char **str, char **save, int END)
{
	char	*newline;
	char	*new_save;
	int		index;

	index = 0;
	if (!*line)
	{
		*line = ft_strldup("", 0, 0);
	}
	// 改行があったら
	if ((newline = ft_strchr(*str, '\n')))
	{
		index = newline - *str + 1;
		*line = ft_strljoin(*line, *str, index - 1);
		// あまりがあったら
		if (index != (int)ft_strlen(*str))
		{
			if (str == save)
			{
				// *save = ft_strldup(*save + index, ft_strlen(*save + index), 0);
				new_save = ft_strldup(*save + index, ft_strlen(*save + index), 0);
				free(*save);
				*save = new_save;
			}
			else
			{
				// *save = ft_strldup(*str + index, ft_strlen(*str + index), 0);
				new_save = ft_strldup(*str + index, ft_strlen(*str + index), 0);
				free(*save);
				*save = new_save;
			}
			return (1);
		}
		free(*save);
		*save = NULL;
		return (1);
	}
	// 改行がなくてEOFフラグが立っていたら
	else if (END)
	{
		*line = ft_strljoin(*line, *str, ft_strlen(*str) + 1);
		free(*save);
		*save = NULL;
		return (2);
	}
	// 改行がなかったら
	// lineにstrをつめる、saveはから
	// printf("line←save\n");
	// printf("line1: %s\n", *line);
	*line = ft_strljoin(*line, *str, ft_strlen(*str) + 1);
	free(*save);
	*save = NULL;
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*save;
	char		*buf;
	static int	END;
	int			bytes;
	int			done;

	done = 0;
	// saveがあったら
	if (BUFFER_SIZE < 1 || !line)
		return (-1);
	*line = NULL;
	if (save)
	{
		// 一行読み終わったかどうか = read
		done = newline_in_str(line, &save, &save, END);
		if (done)
		{
			if (done == 2)
				return (0);
			return (1);
		}
	}
	else if (END)
	{
		*line = ft_strldup("", 0, 0);
		return (0);
	}
	// printf("F2: line1: %s\n", *line);
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (-1);
	while (!done && (bytes = read(fd, buf, BUFFER_SIZE)) > 0)
	{
	// printf("while: %s\n", buf);
		if (bytes < BUFFER_SIZE)
		{
			END = 1;
		}
		buf[bytes] = '\0';
		done = newline_in_str(line, &buf, &save, END);
		if (done)
		{
			free(buf);
			if (done == 2)
				return (0);
			return (1);
		}
	}
	if (done == -1 || bytes == -1)
	{
	// printf("done: line1: %s\n", buf);
		free(buf);
		return (-1);
	}
	if (bytes == 0 && !*line)
	{
	// printf("bytes: line1: %d\n", bytes);
		free(buf);
		*line = ft_strldup("", 0, 0);
		return (0);
	}
	return (0);
}
